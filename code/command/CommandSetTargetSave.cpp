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

#include "CommandSetTargetSave.h"
#include "../camera/Camera.h"

CommandSetTargetSave::CommandSetTargetSave(Camera* camera1, std::string target, std::string path, tinyxml2::XMLNode* node):Command(camera1,node){
	this->target = string(target);
	this->path = string(path);
}

int CommandSetTargetSave::execute(){
	if (this->target.compare("camera") && this->target.compare("host") && this->target.compare("both")) {
		ResponseMsg response = ResponseMsg(CAMERROR_VALUE_NOT_SUPPORTED,"Target unsoported. It only can be camera, host or both");
		OutputWriter::WriteToDoc(response,this->nodeOut);
		return response.getCode();
	}
	

	//TODO Check path
	if (this->target.compare("camera") && !checkDirectoryExists(path)){	//If target is not camera and the drectory of the path doesnt exists
		ResponseMsg response = ResponseMsg(CAMERROR_VALUE_UNKNOWN,"The directory specified doesn't exists");
		OutputWriter::WriteToDoc(response,this->nodeOut);
		return response.getCode();
	}

	if (path.empty() && this->target.compare("camera")) //If the target is not camera and the path is empty (path not provided and not default path)
	{		
		ResponseMsg response = ResponseMsg(CAMERROR_VALUE_UNKNOWN,"There is not directory to save the images");
		OutputWriter::WriteToDoc(response,this->nodeOut);
		return response.getCode();
	}
	else{	
		camera->setTargetPhotos(target);
		if (this->target.compare("camera"))	//Only set path if target is not camera
			camera->setPathSavePhotos(path);
		ResponseMsg response = camera->setTargetSave();
		OutputWriter::WriteToDoc(response,this->nodeOut);
		return response.getCode();
	}
}

bool CommandSetTargetSave::checkDirectoryExists(const std::string& dirName_in){
  DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    return false;  //something is wrong with your path!

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return true;   // this is a directory!

  return false;    // this is not a directory!
};

