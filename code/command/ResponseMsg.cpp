#include "ResponseMsg.h"

ResponseMsg::ResponseMsg(int code, const char* message){
	this->code=code;
	this->message=message;
}

int ResponseMsg::getCode(){
	return this->code;
}

const char* ResponseMsg::getMessage(){
	return this->message;
}