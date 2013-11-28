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

#ifndef Command_h
#define Command_h


#include "Camera.h"
#include "tinyxml2.h"
class Command
{
protected:
	Camera* camera; //Camera command target
	tinyxml2::XMLNode* nodeOut; //Node for write output
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor.
	 *
	 * @param [in,out]	c	If non-null, the Camera* to process.
	 **************************************************************************************************/
	Command (Camera* c);

	/**********************************************************************************************//**
	 * @brief	Constructor with node.
	 *
	 * @param [in,out]	c   	The Camera* to process.
	 * @param [in,out]	node	The node.
	 **************************************************************************************************/
	Command (Camera* c, tinyxml2::XMLNode* node);
	
	/**********************************************************************************************//**
	 * @brief	Execute the command.
	 *
	 * @return	integer for notify error. If the code is negative, an error has occurred.
	 **************************************************************************************************/
	virtual int execute(){return -1;};
};

#endif /* Command_h */