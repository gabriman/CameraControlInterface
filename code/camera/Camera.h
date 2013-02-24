#ifndef Camera_h
#define Camera_h

#include <iostream>

using namespace std;

class Camera {

public: 
	Camera() {}; //Constructor
	virtual void init(){};
	virtual void close(){};
	virtual void operacion1(){};
};
#endif /* Camera_h */