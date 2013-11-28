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
	//TODO Check path
	if (!path.empty() || !this->target.compare("camera"))
	{
		camera->setTargetPhotos(target);
		camera->setPathSavePhotos(path);	//If path have value, set. If is empty, hold previous path
		ResponseMsg response = camera->setTargetSave();
		OutputWriter::WriteToDoc(response,this->nodeOut);
		return response.getCode();
	}
	else{	//If the target is not camera and the path is empty (path not provided and not default path)
		ResponseMsg response = ResponseMsg(CAMERROR_VALUE_UNKNOWN,"There isn't directory to save the images");
		OutputWriter::WriteToDoc(response,this->nodeOut);
		return response.getCode();
	}
};