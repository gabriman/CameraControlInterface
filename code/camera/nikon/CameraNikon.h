#ifndef CameraNikon_h
#define CameraNikon_h

#include "Camera.h"

class CameraNikon: public Camera
{
public:
	CameraNikon();
	ResponseMsg init();
	ResponseMsg operacion1();
	ResponseMsg close();
//	LPMAIDEntryPointProc pMAIDEntryPoint;
//private:
//	unsigned long cameraID;
//	tagRefObj* pRefMod;
//	tagRefObj* pRefSrc;
};

#endif /* CameraNikon_h */