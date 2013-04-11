#ifndef Camera_h
#define Camera_h

#include <iostream>

using namespace std;

class Camera {

protected:
	string company;
	string model;

public: 
	virtual void init(){};
	virtual void close(){};
	virtual void operacion1(){};
	virtual void setProperty(string prop, const char * value){};
	virtual void getProperty(string prop, char** value){};
	virtual void takePicture(){};
};
#endif /* Camera_h */