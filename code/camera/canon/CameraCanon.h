#ifndef CameraCanon_h
#define CameraCanon_h

#include "../Camera.h"

class CameraCanon : public Camera
{
public:
	CameraCanon();
	void init();
	void operacion1();
	void close();
};

#endif /* CameraCanon_h */