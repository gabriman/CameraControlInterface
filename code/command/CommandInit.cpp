#include "CommandInit.h"
#include "../camera/Camera.h"

CommandInit::CommandInit(Camera* camera1):Command(camera1){}

int CommandInit::execute(){
	cout<<"Ejecutando Init"<<endl;
	ResponseMsg response = camera->init();
	OutputWriter::WriteInitOutput(response);
	return response.getCode();
};