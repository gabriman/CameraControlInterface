#include "CameraCanon.h"

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
	else return ResponseMsg(CAMERROR_OK,"");
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

ResponseMsg CameraCanon::takePicture()
{
	err = EdsSendCommand(camera , kEdsCameraCommand_TakePicture , 0);
	if (err == EDS_ERR_OK) return ResponseMsg(CAMERROR_OK,"");
	else return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Error taking photo");
}


//PRIVATE SECTION
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