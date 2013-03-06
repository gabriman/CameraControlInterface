#ifndef CameraCanon_h
#define CameraCanon_h

#include "../Camera.h"
#include "EDSDK.h"
#include "EDSDKTypes.h"
#include <map>
#include "dictionary\DictionaryCanon.h"

class CameraCanon : public Camera
{
private:
	EdsCameraRef camera;
	EdsError err;
	bool isSDKLoaded;
	std::map<EdsUInt32, const char *> _propertyTableISO;
	DictionaryCanon dictionary;

public:
	CameraCanon();
	void init();
	void setProperty(string prop, const char * value);
	void operacion1();
	void close();
	void operacionExclusiva(){};

private:
	EdsError getFirstCamera(EdsCameraRef *camera);
};

#endif /* CameraCanon_h */