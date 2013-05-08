#include "CameraCanon.h"


/**********************************************************************************************//**
 * @brief	Default constructor.
 **************************************************************************************************/
CameraCanon::CameraCanon(){

	CameraCanon::company="Canon";
	camera = NULL;
	err = EDS_ERR_OK;
	isSDKLoaded = false;
	DictionaryCanon dictionary;

}


ResponseMsg CameraCanon::init(){
	// Initialize SDK
	err = EdsInitializeSDK();
	if(err == EDS_ERR_OK)
	{
		isSDKLoaded = true;
	}
	if (err==EDS_ERR_MISSING_SUBCOMPONENT){
		cout<<"EDS_ERR_MISSING_SUBCOMPONENT"<<cout;
	}
	// Get first camera
	if(err == EDS_ERR_OK)
	{
		err = getFirstCamera (&camera);
	}

	if(err == EDS_ERR_OK)
	{
		err=EdsOpenSession(camera);
	}

	if (err != EDS_ERR_OK) return ResponseMsg(CAMERROR_CAMERA_NOT_CONECTED,"Camera not conected");
	else{
		/*EdsUInt32 saveto = kEdsSaveTo_Host;
		err = EdsSetPropertyData(camera, kEdsPropID_SaveTo, 0, sizeof(EdsUInt32), &saveto);*/

		//Register events handler
		//err = EdsSetPropertyEventHandler(camera, kEdsPropertyEvent_All, ListenerCanon::handlePropertyEvent, NULL);
		if(err != EDS_ERR_OK) {
			printf("Canon: error, cannot set property event handler.\n");
		}
		//err = EdsSetCameraStateEventHandler(camera,kEdsStateEvent_All,ListenerCanon::handleStateEvent,NULL);
		//if(err != EDS_ERR_OK) {
		//	printf("Canon: error, cannot set state event handler.\n");
		//}		
		err = EdsSetObjectEventHandler(camera,  kEdsObjectEvent_All, ListenerCanon::handleObjectEvent,  NULL); 
		if(err != EDS_ERR_OK) {
			printf("Canon: error, cannot set object event handler.\n");
		}

		
		//Lauch thread with observer loop
		//ListenerCanon::dispathMsg(NULL);
		//ListenerCanon::runThreadObserver();  //DONT WORK YET, UNTIL NOW, call function manually

		return ResponseMsg(CAMERROR_OK,"");
		
	}
}



ResponseMsg CameraCanon::close(){
	// Close session with camera
	if(err == EDS_ERR_OK)
	{
		err = EdsCloseSession(camera);
	}
	else return ResponseMsg(CAMERROR_CAMERA_NOT_CONECTED,"Camera not conected");
	// Release camera
	if(camera != NULL)
	{
		EdsRelease(camera);
	}
	// Terminate SDK
	if(isSDKLoaded)
	{
		EdsTerminateSDK();
	}
	return ResponseMsg(CAMERROR_OK,"");
}



ResponseMsg CameraCanon::setProperty(string prop, const char * value)
{
	int propEds = 0;
	if		(!prop.compare("ISO")) propEds = kEdsPropID_ISOSpeed;
	else if (!prop.compare("SPEED")) propEds = kEdsPropID_Tv;
	else if (!prop.compare("APERTURE")) propEds = kEdsPropID_Av;
	else return ResponseMsg(CAMERROR_PROP_UNAVALIABLE,"Property not supported");

	EdsUInt32 valueEds = dictionary.translate(prop,value);
	if (valueEds==0xffffffff) return ResponseMsg(CAMERROR_VALUE_NOT_SUPPORTED,"Value not suported");

	EdsSetPropertyData(camera, propEds, 0 , sizeof(valueEds), &valueEds);
	return ResponseMsg(CAMERROR_OK,"");
}



ResponseMsg CameraCanon::getProperty(string prop)
{
	int propEds = 0;
	if		(!prop.compare("ISO")) propEds = kEdsPropID_ISOSpeed;
	else if (!prop.compare("SPEED")) propEds = kEdsPropID_Tv;
	else if (!prop.compare("APERTURE")) propEds = kEdsPropID_Av;
	else return ResponseMsg(CAMERROR_PROP_UNAVALIABLE,"Property not supported");

	EdsError err = EDS_ERR_OK;
	EdsDataType dataType;
	EdsUInt32 dataSize;

	EdsUInt32 edsValue;
	err = EdsGetPropertySize(camera, propEds, 0 , &dataType, &dataSize);
	if(err == EDS_ERR_OK)
	{
		err = EdsGetPropertyData(camera, propEds, 0 , dataSize, &edsValue);
	}
	else return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");

	const char * valueTranslate = dictionary.translate(prop,edsValue);
	if (valueTranslate=="unknown") return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");

	return ResponseMsg(CAMERROR_OK,valueTranslate);
};



ResponseMsg CameraCanon::getGetList(string prop)
{
	int propEds = 0;
	if		(!prop.compare("ISO")) propEds = kEdsPropID_ISOSpeed;
	else if (!prop.compare("SPEED")) propEds = kEdsPropID_Tv;
	else if (!prop.compare("APERTURE")) propEds = kEdsPropID_Av;
	else return ResponseMsg(CAMERROR_PROP_UNAVALIABLE,"Property not supported");

	EdsError err = EDS_ERR_OK;
	EdsPropertyDesc *propDesc = new EdsPropertyDesc;

	if(err == EDS_ERR_OK)
	{
		err = EdsGetPropertyDesc(camera, propEds, propDesc);
	}
	else return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");
	
	if (err == EDS_ERR_OK){
		string stringResponse="";
		char * valueTranslate;
		for (int i=0;i<propDesc->numElements;i++){
			valueTranslate = (char *)dictionary.translate(prop,propDesc->propDesc[i]);
			stringResponse.append(valueTranslate);
			stringResponse.append(";");
		}
		return ResponseMsg(CAMERROR_OK,stringResponse);
	}
	else if (err == EDS_ERR_INVALID_PARAMETER)
		return ResponseMsg(CAMERROR_PROP_UNAVALIABLE,"Property not supported");

	//const char * valueTranslate = dictionary.translate(prop,edsValue);
	//if (valueTranslate=="unknown") return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");
	
	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Error");
};



ResponseMsg CameraCanon::takePicture()
{
	err = EdsSendCommand(camera , kEdsCameraCommand_TakePicture , 0);
	if (err == EDS_ERR_OK) {	
		MSG Msg;
		while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE)>0){
			cout<<"dentro de bucle peek"<<endl;
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
			Sleep(1000);
		}
		cout<<"ACABO DE ESPERAR"<<endl;
		return ResponseMsg(CAMERROR_OK,"");
	}
	else return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Error taking photo");
}




//PRIVATE SECTION

/**********************************************************************************************//**
 * @brief	Getting a camera object
 *
 * @param [out]	camera	The first camera
 *
 * @return	Notify error
 **************************************************************************************************/
EdsError CameraCanon::getFirstCamera(EdsCameraRef *camera)
{
	EdsError err = EDS_ERR_OK;
	EdsCameraListRef cameraList = NULL;
	EdsUInt32 count = 0;
	// Get camera list
	err = EdsGetCameraList(&cameraList);
	// Get number of cameras
	if(err == EDS_ERR_OK)
	{
		err = EdsGetChildCount(cameraList, &count);
		if(count == 0)
		{
			err = EDS_ERR_DEVICE_NOT_FOUND;
		}
	}
	// Get first camera retrieved
	if(err == EDS_ERR_OK)
	{
		err = EdsGetChildAtIndex(cameraList , 0 , camera);
	}
	// Release camera list
	if(cameraList != NULL)
	{
		EdsRelease(cameraList);
		cameraList = NULL;
	}

	return 0;
}

//bool CameraCanon::preCommand(){
//
//        printf("pre command \n");
//
//        if( state > CAMERA_UNKNOWN ){
//            needToOpen = false;
//            bool readyToGo  = false;
//
//            if( state != CAMERA_OPEN ){
//                needToOpen = true;
//            }else{
//                readyToGo = true;
//                return true;
//            }
//
//            if( needToOpen ){
//                readyToGo = openSession();
//            }
//
//            return readyToGo;
//
//        }else{
//            return false;
//        }
//
//    }


 bool CameraCanon::downloadLastImage(){
        //preCommand();
        

        EdsVolumeRef 		theVolumeRef	    = NULL ;
        EdsDirectoryItemRef	dirItemRef_DCIM	    = NULL;
        EdsDirectoryItemRef	dirItemRef_Sub	    = NULL;
        EdsDirectoryItemRef	dirItemRef_Image    = NULL;

        EdsDirectoryItemInfo dirItemInfo_Image;

        EdsError err    = EDS_ERR_OK;
		
		EdsCameraListRef cameraList = NULL;
        EdsUInt32 Count = 0;
        bool success    = false;
		
        //get the number of memory devices
		err = EdsGetChildCount( this->camera, &Count );
        if( Count == 0 ){
            printf("Memory device not found\n");
            err = EDS_ERR_DEVICE_NOT_FOUND;
            return false;
        }

        // Download Card No.0 contents
        err = EdsGetChildAtIndex( this->camera, 0, &theVolumeRef );
//        if ( err == EDS_ERR_OK ){
//            printf("getting volume info\n");
//            //err = EdsGetVolumeInfo( theVolumeRef, &volumeInfo ) ;
//        }

        //Now lets find out how many Folders the volume has
        if ( err == EDS_ERR_OK ){
            err = EdsGetChildCount( theVolumeRef, &Count );

            if ( err == EDS_ERR_OK ){

                //Lets find the folder called DCIM
                bool bFoundDCIM = false;
                for(int i = 0; i < Count; i++){
                    err = EdsGetChildAtIndex( theVolumeRef, i, &dirItemRef_DCIM ) ;
                    if ( err == EDS_ERR_OK ){
                        EdsDirectoryItemInfo dirItemInfo;
                        err = EdsGetDirectoryItemInfo( dirItemRef_DCIM, &dirItemInfo );
                        if( err == EDS_ERR_OK){
                            string folderName = dirItemInfo.szFileName;
                            if( folderName == "DCIM" ){
                                bFoundDCIM = true;
                                printf("Found the DCIM folder at index %i\n", i);
                                break;
                            }
                        }
                    }
                    //we want to release the directories that don't match
                    easyRelease(dirItemRef_DCIM);
                }

                //This is a bit silly.
                //Essentially we traverse into the DCIM folder, then we go into the last folder in there, then we
                //get the last image in last folder.
                if( bFoundDCIM && dirItemRef_DCIM != NULL){
                    //now we are going to look for the last folder in DCIM
                    Count = 0;
                    err = EdsGetChildCount(dirItemRef_DCIM, &Count);

                    bool foundLastFolder = false;
                    if( Count > 0 ){
                        int lastIndex = Count-1;

                        EdsDirectoryItemInfo dirItemInfo_Sub;

                        err = EdsGetChildAtIndex( dirItemRef_DCIM, lastIndex, &dirItemRef_Sub ) ;
                        err = EdsGetDirectoryItemInfo( dirItemRef_Sub, &dirItemInfo_Sub);

                        printf("Last Folder is %s \n", dirItemInfo_Sub.szFileName);

                        EdsUInt32 jpgCount = 0;
                        err = EdsGetChildCount(dirItemRef_Sub, &jpgCount );

                        if( jpgCount > 0 ){
                            int latestJpg = jpgCount-1;

                            err = EdsGetChildAtIndex(dirItemRef_Sub, latestJpg, &dirItemRef_Image ) ;
                            err = EdsGetDirectoryItemInfo(dirItemRef_Image, &dirItemInfo_Image);

                            printf("Latest image is %s \n", dirItemInfo_Image.szFileName);
                            success = true;
                        }else{
                            printf("Error - No jpegs inside %s\n", dirItemInfo_Image.szFileName);
                        }
                    }else{
                        printf("Error - No subfolders inside DCIM!\n");
                    }
                }
            }
        }
        //if( success ){
        //    success = downloadImage(dirItemRef_Image);
        //}

        //easyRelease(theVolumeRef);
        //easyRelease(dirItemRef_DCIM);
        //easyRelease(dirItemRef_Sub);
        //easyRelease(dirItemRef_Image);

        //postCommand();

        return success;
    }


	////---------------------------------------------------------------------
 //bool CameraCanon::downloadImage(EdsDirectoryItemRef directoryItem){
 //     //if( !downloadEnabled ) return false;

 //       EdsError err = EDS_ERR_OK;
 //       EdsStreamRef stream = NULL;
 //       EdsDirectoryItemInfo dirItemInfo;

 //       bool success = false;
 //       string imageName;
 //       string imagePath;

 //       int timeStart = ofGetElapsedTimeMillis();

 //       err = EdsGetDirectoryItemInfo(directoryItem, &dirItemInfo);
 //       if(err == EDS_ERR_OK){

 //           imageName = dirItemInfo.szFileName;
 //           imagePath = downloadPath + imageName;

 //           printf("Downloading image %s to %s\n", imageName.c_str(), imagePath.c_str());
 //           err = EdsCreateFileStream( ofToDataPath( imagePath ).c_str(), kEdsFileCreateDisposition_CreateAlways, kEdsAccess_ReadWrite, &stream);
 //       }

 //       if(err == EDS_ERR_OK){
 //           err = EdsDownload( directoryItem, dirItemInfo.size, stream);
 //       }

 //       if(err == EDS_ERR_OK){

 //           lastImageName = imageName;
 //           lastImagePath = imagePath;

 //           printf("Image downloaded in %ims\n", ofGetElapsedTimeMillis()-timeStart);

 //           err = EdsDownloadComplete(directoryItem);
 //           if( bDeleteAfterDownload ){
 //               printf("Image deleted\n");
 //               EdsDeleteDirectoryItem(directoryItem);
 //           }
 //           success = true;
 //       }

 //       easyRelease(stream);
 //       return success;
 //   }
 
