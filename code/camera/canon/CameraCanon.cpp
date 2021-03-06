//
//Copyright 2013 Gabriel Rodríguez Rodríguez.
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "CameraCanon.h"


/**********************************************************************************************//**
* @brief	Default constructor.
**************************************************************************************************/
CameraCanon::CameraCanon(){
	company="Canon";
	camera = NULL;
	err = EDS_ERR_OK;
	isSDKLoaded = false;
	DictionaryCanon dictionary;
	pathSavePhotos="";
	targetPhotos = "camera";
	setTargetSave();
	setLastPhotoName("");
}

CameraCanon::CameraCanon(string photosDirectory ){
	company="Canon";
	camera = NULL;
	err = EDS_ERR_OK;
	isSDKLoaded = false;
	DictionaryCanon dictionary;
	pathSavePhotos=photosDirectory;	//Load default directory
	targetPhotos = "host";
	setTargetSave();
	setLastPhotoName("");
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
		//Register object events handler
		err = EdsSetObjectEventHandler(camera,  kEdsObjectEvent_All, ListenerCanon::handleObjectEvent,  this); 
		if(err != EDS_ERR_OK) {
			printf("Canon: error, cannot set object event handler.\n");
		}

		//Set Property Event Handler
		if(err == EDS_ERR_OK)
		{
			err = EdsSetPropertyEventHandler( camera, kEdsPropertyEvent_All, ListenerCanon::handlePropertyEvent , this);
		}

		//Set State Event Handler
		if(err == EDS_ERR_OK)
		{
			err = EdsSetCameraStateEventHandler( camera, kEdsStateEvent_All, ListenerCanon::handleStateEvent , this);
		}



		setPhotoDetected(false);

		return ResponseMsg(CAMERROR_OK,"canon");

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
	//First, launch listeners for get actual values (if was changed manually from the camera buttons)
	MSG Msg;
	while (PeekMessage (&Msg, NULL, 0, 0, PM_REMOVE) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	


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

	const char * valueTranslated = dictionary.translate(prop,edsValue);
	if (valueTranslated=="unknown") return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");

	return ResponseMsg(CAMERROR_OK,valueTranslated);
};



ResponseMsg CameraCanon::getGetList(string prop)
{
	//First, launch listeners for get actual values (if was changed manually from the camera buttons)
	MSG Msg;
	while (PeekMessage (&Msg, NULL, 0, 0, PM_REMOVE) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

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
		delete propDesc;
		return ResponseMsg(CAMERROR_OK,stringResponse);
	}
	else if (err == EDS_ERR_INVALID_PARAMETER){
		delete propDesc;
		return ResponseMsg(CAMERROR_PROP_UNAVALIABLE,"Property not supported");
	}

	//const char * valueTranslate = dictionary.translate(prop,edsValue);
	//if (valueTranslate=="unknown") return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");

	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Error");
};


/**********************************************************************************************//**
* @brief	Sets photo detected.
*
* @param	 value	true to detected.
**************************************************************************************************/
void CameraCanon::setPhotoDetected(bool detected){
	photoDetected=detected;
}


/**********************************************************************************************//**
* @brief	Gets photo detected.
*
* @return	true if photo is detected, false if not.
**************************************************************************************************/
bool CameraCanon::getPhotoDetected(){
	return photoDetected;
}


/**********************************************************************************************//**
* @brief	Sets the name of the last photo taked.
*
* @param	 value	true to detected.
**************************************************************************************************/
void CameraCanon::setLastPhotoName(std::string name){
	lastPhotoName=name;
}


/**********************************************************************************************//**
* @brief	Gets photo detected.
*
* @return	true if photo is detected, false if not.
**************************************************************************************************/
std::string CameraCanon::getLastPhotoName(){
	return lastPhotoName;
}



ResponseMsg CameraCanon::takePicture()
{
	cout << "TakePicture start" << endl;
	err = EdsSendCommand(camera , kEdsCameraCommand_TakePicture , 0);
	cout << "TakePicture end" << endl;
	if (err == EDS_ERR_OK) {	
		MSG Msg;
		while(!getPhotoDetected()){
			if (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE)>0){
				TranslateMessage(&Msg);
				DispatchMessage(&Msg);
			}
		}
		setPhotoDetected(false);
		return ResponseMsg(CAMERROR_OK,getLastPhotoName());
	}
	else return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Error taking photo");
}

ResponseMsg CameraCanon::setTargetSave()
{
	//Indicate save image in host
	EdsUInt32 saveto;
	if (!targetPhotos.compare("host"))		saveto = kEdsSaveTo_Host;	
	else if (!targetPhotos.compare("camera"))	saveto = kEdsSaveTo_Camera;
	else if (!targetPhotos.compare("both"))	saveto = kEdsSaveTo_Both;
	else	return ResponseMsg(CAMERROR_COMMAND_FORMAT_ERROR,"Target value not valid");

	err = EdsSetPropertyData(camera, kEdsPropID_SaveTo, 0, sizeof(EdsUInt32), &saveto);
	if (err != EDS_ERR_OK) {
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Error setting save target");
	}
	//We need to tell it how much storage you have on your computer so it knows how
	// many images we can store.
	EdsCapacity newCapacity = {0x7FFFFFFF, 0x1000, 1}; 
	err = EdsSetCapacity(camera, newCapacity );
	if (err != EDS_ERR_OK) {
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Error setting capacity");
	}
	return ResponseMsg(CAMERROR_OK,"");
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

