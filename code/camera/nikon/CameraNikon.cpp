#include "CameraNikon.h"

CameraNikon::CameraNikon(){

}

ResponseMsg CameraNikon::init(){

	cout<<"Camera inicializada NIKON"<<endl;
	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
}

ResponseMsg CameraNikon::operacion1(){

	cout<<"Haciendo operacion 1  NIKON"<<endl;
	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
}

ResponseMsg CameraNikon::close(){

	cout<<"Haciendo  close  NIKON"<<endl;
	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
}