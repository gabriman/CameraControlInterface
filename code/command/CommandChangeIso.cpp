#include "CommandChangeIso.h"
#include "../Camera.h"

CommandChangeIso::CommandChangeIso(Camera* camera1):Command(camera1){}

void CommandChangeIso::execute(){
	cout<<"Ejecutando changeISO"<<endl;
	camera->operacion1();
};