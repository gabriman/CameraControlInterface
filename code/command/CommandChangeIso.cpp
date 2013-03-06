#include "CommandChangeIso.h"
#include "../camera/Camera.h"

CommandChangeIso::CommandChangeIso(Camera* camera1,const char* value):Command(camera1){
	/*newValue=value;*/
	strcpy(newValue,value);
}

void CommandChangeIso::execute(){
	cout<<"Ejecuting changeISO"<<endl;
	camera->setProperty("ISO",newValue);
	cout<<"Iso changed"<<endl;
};