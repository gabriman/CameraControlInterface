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

#include "ResponseMsg.h"

ResponseMsg::ResponseMsg(int code, char* message){
	this->code=code;
	this->message=message;
}

ResponseMsg::ResponseMsg(int code, string message){
	this->code=code;
	this->message = (char *)malloc (sizeof(char *)*message.size());
	strcpy(this->message,(const char *)message.c_str());
}

int ResponseMsg::getCode(){
	return this->code;
}

const char* ResponseMsg::getMessage(){
	return this->message;
}