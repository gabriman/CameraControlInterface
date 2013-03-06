#include "CameraCanon.h"

CameraCanon::CameraCanon(){

	CameraCanon::company="Canon";
	camera = NULL;
	err = EDS_ERR_OK;
	isSDKLoaded = false;
	DictionaryCanon dictionary;
	
}

void CameraCanon::init(){

	cout<<"Camera inicializada CANON"<<endl;

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

}

void CameraCanon::operacion1(){

	cout<<"Haciendo operacion 1 CANON"<<endl;
	cout<<"......"<<endl;
	Sleep(1500);
	cout<<"operacion 1 REALIZADA CANON"<<endl;
}

void CameraCanon::close(){

	cout<<"Haciendo  close CANON"<<endl;

	////
	// Close session with camera
	if(err == EDS_ERR_OK)
	{
		err = EdsCloseSession(camera);
	}
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
}


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



void CameraCanon::setProperty(string prop, const char * value){


	EdsUInt32 valueEds = dictionary.translate(prop,value);
	EdsSetPropertyData(camera, kEdsPropID_ISOSpeed, 0 , sizeof(valueEds), &valueEds);


	//EdsUInt32 a;
	//EdsUInt32 value = _propertyTableISO.


}