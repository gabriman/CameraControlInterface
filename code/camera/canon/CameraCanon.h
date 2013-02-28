#ifndef CameraCanon_h
#define CameraCanon_h

#include "../Camera.h"
#include "EDSDK.h"
#include "EDSDKTypes.h"

class CameraCanon : public Camera
{
private:
	EdsCameraRef camera;
	EdsError err;
	bool isSDKLoaded;

public:
	CameraCanon();
	void init();
	void operacion1();
	void close();
	void operacionExclusiva(){};

private:
	EdsError getFirstCamera(EdsCameraRef *camera);
};

#endif /* CameraCanon_h */