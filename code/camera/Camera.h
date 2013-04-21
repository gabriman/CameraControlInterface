#ifndef Camera_h
#define Camera_h

#include <iostream>
#include "../command/ResponseMsg.h"

#define CAMERROR_OK 0
#define CAMERROR_ERROR_UNDEFINED -1
#define CAMERROR_CAMERA_NOT_CONECTED -2
#define CAMERROR_PROP_UNAVALIABLE -3
#define CAMERROR_VALUE_NOT_SUPPORTED -4
#define CAMERROR_VALUE_UNKNOWN -5
#define CAMERROR_COMMAND_FORMAT_ERROR -6

using namespace std;

class Camera {

protected:
	string company;
	string model;

public: 
	virtual ResponseMsg init(){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};
	virtual ResponseMsg close(){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};
	virtual ResponseMsg setProperty(string prop, const char * value){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};
	virtual ResponseMsg getProperty(string prop){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};
	virtual ResponseMsg getGetList(string prop){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};
	virtual ResponseMsg takePicture(){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};
};
#endif /* Camera_h */