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
};

#endif /* CameraNikon_h */