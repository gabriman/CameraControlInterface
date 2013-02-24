#ifndef CameraNikon_h
#define CameraNikon_h

#include "../Camera.h"

class CameraNikon: public Camera
{
public:
	CameraNikon();
	void init();
	void operacion1();
	void close();
};

#endif /* CameraNikon_h */