#include "CommandSetIso.h"
#include "../camera/Camera.h"

CommandSetIso::CommandSetIso(Camera* camera1,const char* value):Command(camera1){
	/*newValue=value;*/
	strcpy_s(newValue,value);
}

void CommandSetIso::execute(){
	cout<<"Ejecuting changeISO"<<endl;
	camera->setProperty("ISO",newValue);
	cout<<"Iso changed"<<endl;
};