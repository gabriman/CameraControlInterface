#ifndef CameraCanon_h
#define CameraCanon_h

#include "Camera.h"
#include "EDSDK.h"
#include "EDSDKTypes.h"
#include <map>
#include "DictionaryCanon.h"
#include "ListenerCanon.h"

class CameraCanon : public Camera
{
private:
	EdsCameraRef camera;
	EdsError err;
	bool isSDKLoaded;
	DictionaryCanon dictionary;
	bool photoDetected;
	
public:
	CameraCanon();
	ResponseMsg init();
	ResponseMsg setProperty(string prop, const char * value);
	ResponseMsg getProperty(string prop);
	ResponseMsg getGetList(string prop);
	void setPhotoDetected(bool value);
	bool getPhotoDetected();
	ResponseMsg close();
	ResponseMsg takePicture();
	bool downloadLastImage();
private:
	EdsError getFirstCamera(EdsCameraRef *camera);
	//bool downloadImage(EdsDirectoryItemRef directoryItem);
	//bool preCommand();
	static void easyRelease(EdsBaseRef &ref){
    if(ref != NULL){
        EdsRelease(ref);
        ref = NULL;
    }
}

};

#endif /* CameraCanon_h */