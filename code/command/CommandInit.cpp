#include "CommandInit.h"
#include "../camera/Camera.h"

CommandInit::CommandInit(Camera* camera1):Command(camera1){}

int CommandInit::execute(){
	cout<<"Ejecutando Init"<<endl;
	camera->init();
	return 0;
};