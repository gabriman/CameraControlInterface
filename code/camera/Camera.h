//
//Copyright 2013 Gabriel Rodríguez Rodríguez.
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.

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
	string pathSavePhotos; //Only when "save in host" is enable
	string targetPhotos; //Only when "save in host" is enable

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


	/**********************************************************************************************//**
	 * @brief	Sets target to save images.
	 *
	 * @param	target	Target (camera,host,both).
	 *
	 * @return	.
	 **************************************************************************************************/
	virtual ResponseMsg setTargetSave(){return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");};


	void setPathSavePhotos(string pathSave){ this->pathSavePhotos=pathSave;};
	
	string getPathSavePhotos() {return this->pathSavePhotos;};
	
	void setTargetPhotos(string target){ this->targetPhotos=target;};
	
	string getTargetPhotos() {return this->targetPhotos;};

};
#endif /* Camera_h */