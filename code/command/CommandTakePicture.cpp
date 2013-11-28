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

#include "CommandTakePicture.h"
#include "../camera/Camera.h"

CommandTakePicture::CommandTakePicture(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

int CommandTakePicture::execute(){
	ResponseMsg response = camera->takePicture();
	OutputWriter::WriteToDoc(response,this->nodeOut);
	return response.getCode();
};