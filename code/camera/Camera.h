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

	/**********************************************************************************************//**
	 * @brief	Initialises this camera.
	 *
	 * @return	Response message
	 **************************************************************************************************/
	virtual ResponseMsg init(){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};

	/**********************************************************************************************//**
	 * @brief	Close camera
	 *
	* @return	Response message
	**************************************************************************************************/
	virtual ResponseMsg close(){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};

	/**********************************************************************************************//**
	 * @brief	Sets a property.
	 *
	 * @param	prop 	The property to set.
	 * @param	value	The new value.
	 *
	 * @return	Response message
	 **************************************************************************************************/
	virtual ResponseMsg setProperty(string prop, const char * value){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};

	/**********************************************************************************************//**
	 * @brief	Gets a property.
	 *
	 * @param	prop	The property to get.
	 *
	 * @return	Response message. The value is included.
	 **************************************************************************************************/
	virtual ResponseMsg getProperty(string prop){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};

	/**********************************************************************************************//**
	 * @brief	Gets list of possibe values for a property.
	 *
	 * @param	prop	The property.
	 *
	 * @return	The list of values.
	 **************************************************************************************************/
	virtual ResponseMsg getGetList(string prop){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};

	/**********************************************************************************************//**
	 * @brief	Take picture
	 *
	 * @return	Response message for notify errors or successful operation
	 **************************************************************************************************/
	virtual ResponseMsg takePicture(){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};

};
#endif /* Camera_h */