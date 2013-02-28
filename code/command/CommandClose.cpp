#include "CommandClose.h"
#include "../camera/Camera.h"

CommandClose::CommandClose(Camera* camera1):Command(camera1){}

void CommandClose::execute(){
	cout<<"Ejecutando Close"<<endl;
	camera->close();

};