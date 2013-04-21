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