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

#include "CommandInit.h"
#include "../camera/Camera.h"

CommandInit::CommandInit(Camera* camera1):Command(camera1){}

int CommandInit::execute(){
	cout<<"Inicialitation camera"<<endl;
	ResponseMsg response = camera->init();
	OutputWriter::WriteInitOutput(response);
	return response.getCode();
};