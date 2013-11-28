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

#ifndef CommandTakePicture_h
#define CommandTakePicture_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command take picture.
 **************************************************************************************************/
class CommandTakePicture : public Command
{
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandTakePicture (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandTakePicture_h */