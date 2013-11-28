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

#include "CommandSetAperture.h"
#include "../camera/Camera.h"

CommandSetAperture::CommandSetAperture(Camera* camera1,const char* value, tinyxml2::XMLNode* node):Command(camera1,node){
	/*newValue=value;*/
	strcpy_s(newValue,value);
}

int CommandSetAperture::execute(){
	ResponseMsg response = camera->setProperty("APERTURE",newValue);
	OutputWriter::WriteToDoc(response,this->nodeOut,newValue);
	return response.getCode();
};