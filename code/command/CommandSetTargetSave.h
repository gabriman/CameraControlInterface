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

#ifndef CommandSetTargetSave_h
#define CommandSetTargetSave_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command to set the target where photo are saved.
 **************************************************************************************************/
class CommandSetTargetSave : public Command
{
private:
	string target;
	string path;
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandSetTargetSave (Camera* camera1, std::string target, std::string path, tinyxml2::XMLNode* node);
	virtual int execute();
private:
	bool checkDirectoryExists(const std::string& dirName_in);
};

#endif /* CommandSetAperture_h */