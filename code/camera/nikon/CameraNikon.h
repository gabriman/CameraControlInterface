#ifndef CameraNikon_h
#define CameraNikon_h

#include "Camera.h"

#ifdef __cplusplus  
    extern "C" {     
	#endif  
	//Include Nikon
	#include	<stdlib.h>
	#include	<stdio.h>
	#include	"maid3.h"
	#include	"maid3d1.h"
	#include	"CtrlSample.h"

	#ifdef __cplusplus  
     }  
#endif

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