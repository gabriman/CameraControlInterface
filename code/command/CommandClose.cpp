#include "CommandClose.h"
#include "../camera/Camera.h"

CommandClose::CommandClose(Camera* camera1):Command(camera1){}

int CommandClose::execute(){
	cout<<"Ejecutando Close"<<endl;
	camera->close();
	exit(0);
	return 0;
};