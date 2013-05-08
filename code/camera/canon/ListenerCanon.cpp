#include "ListenerCanon.h"


EdsError EDSCALLBACK ListenerCanon::handleStateEvent(
					 EdsUInt32 inEvent
					,EdsUInt32 inParam
					,EdsVoid* inContext
)
{
	cout<<"Canon: handleStateEvent detected.\n"<<endl;
	EdsError error = EDS_ERR_OK;
	switch(inEvent) {
		// Connection with camera lost (maybe power off?)
		case kEdsStateEvent_Shutdown: {
			//Canon::instance().shutdownSDK(true);
			break;	
		}
		case kEdsStateEvent_All:{cout<<"EVENT ALL"<<endl;}
		default:break;
	};
	return error;
}


EdsError EDSCALLBACK ListenerCanon::handlePropertyEvent(
					EdsPropertyEvent inEvent
					,EdsUInt32 inPropertyID
					,EdsUInt32 inParam
					,EdsVoid* inContext)
{
	cout<<"Canon: handlePropertyEvent property.\n"<<endl;
	switch(inEvent) {
		case kEdsPropertyEvent_PropertyChanged: {
			/*
			if(inPropertyID == kEdsPropID_AvailableShots) {
				EdsUInt32 data;
				err = EdsGetPropertyData(Canon::instance().camera, kEdsPropID_AvailableShots, 0, data_size	,&data);
				printf("There are a couple of images available on the cam: %d\n", (int)inParam);
			}
			*/
			//Canon::instance().getProperty(inPropertyID);
			break;
		};

		default:break;
	};
	EdsError error = EDS_ERR_OK;
	return error ;
}



EdsError EDSCALLBACK ListenerCanon::handleObjectEvent( EdsObjectEvent inEvent, EdsBaseRef  object, EdsVoid * context)
{ 
   printf ("Object Event triggered\n");

   //CanonEDCamera* mmCanon = (CanonEDCamera*) g_Self;
  
   switch(inEvent) 
   { 
      case kEdsObjectEvent_DirItemCreated: 
         {
			 cout<<"New photo detected"<<endl;
			 break;
   //         EdsError err = EDS_ERR_OK;
   //         EdsStreamRef stream = NULL;

   //         EdsDirectoryItemInfo dirItemInfo;
   //         err = EdsGetDirectoryItemInfo(object, &dirItemInfo);

   //         // do we need to notify the camera?
   //         /*
   //          if (err == EDS_ERR_OK)
   //          {
   //          CameraEvent e("DownloadStart");
   //          _model->notifyObservers(&e);
   //          }
   //          */

   //         if (err == EDS_ERR_OK)
   //         {
   //            //err = EdsCreateFileStream(dirItemInfo.szFileName, kEdsFileCreateDisposition_CreateAlways, kEdsAccess_ReadWrite, &stream);
   //            err = EdsCreateMemoryStream(0, &stream);
   //         }

   //         // Set Progress Callback???

   //         // Download Image
   //         if (err == EDS_ERR_OK)
   //         {
   //            err = EdsDownload(object,  dirItemInfo.size, stream);
   //         }

   //         if (err == EDS_ERR_OK)
   //         {
   //            err = EdsDownloadComplete(object);
   //         }

   //         EdsImageRef imageRef = NULL;

   //         if (err == EDS_ERR_OK)
   //         {
   //            err = EdsCreateImageRef(stream, &imageRef);
   //         }

   //         EdsImageInfo imageInfo;

   //         if (err == EDS_ERR_OK)
   //         {
   //            err = EdsGetImageInfo(imageRef, kEdsImageSrc_FullView, &imageInfo);
   //         }
   //         if (err == EDS_ERR_OK)
   //         {
   //            printf ("Image Width: %d\n", imageInfo.width);
   //         }
		 }
         case kEdsObjectEvent_DirItemRequestTransfer: 
         {
			 cout<<"New photo requesting transfer"<<endl;
			 break;
		 }


         
   //      break; 
   //     
   //      default: 
   //       
   //      break; 
      } 
   // 
 
   // Object must be released 
   if(object) 
   { 
      EdsRelease(object); 
   } 	
   EdsError error = EDS_ERR_OK;
   return error ;
} 

DWORD WINAPI ListenerCanon::dispathMsg(LPVOID lpParam)
{
	MSG msg;	
	cout<<"Nuevo mensaje"<<endl;
	//GetMessage(&msg, 0, 0, 0);
	TranslateMessage(&msg); 
	DispatchMessage(&msg); 
	return 0;
}

DWORD WINAPI ListenerCanon::dispathMsgLoop(LPVOID lpParam)
{
	MSG msg;	
	cout<<"nuevo thread"<<endl;
//	while (GetMessage(&msg, 0, 0, 0)) 
	while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		cout<<"Nuevo mensaje dentro de loop"<<endl;
		TranslateMessage(&msg); 
		DispatchMessage(&msg); 
	}
	return 0;
}


bool ListenerCanon::runThreadObserver(){
	 int data = 0;

	 int numThreads = 1;
	 DWORD   dwThreadIdArray[1];
    HANDLE  hThreadArray[1]; 

	 hThreadArray[0] = CreateThread (
      NULL,       // Atributo de seguridad: Usar el de la thread actual
      0,          // Tamaño del stack. Usar el tamaño por defecto
      dispathMsgLoop, // Función inicial de la thread
      &data,    // Datos a pasar a la thread
      0,          // Flags de creación
      &dwThreadIdArray[0]);

	 if (hThreadArray[0] == NULL) 
        {
           cout<<"ERROR createThread"<<endl;;
           ExitProcess(3);
        }
    
	 
    WaitForMultipleObjects(numThreads, hThreadArray, TRUE, INFINITE);

     for(int i=0; i<numThreads; i++)
    {
        CloseHandle(hThreadArray[i]);
    }

  return true;
}