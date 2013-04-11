#include "CommandSetSpeed.h"
#include "../camera/Camera.h"

CommandSetSpeed::CommandSetSpeed(Camera* camera1,const char* value):Command(camera1){
	/*newValue=value;*/
	strcpy_s(newValue,value);
}

void CommandSetSpeed::execute(){
	cout<<"Ejecuting changeISO"<<endl;
	camera->setProperty("SPEED",newValue);
	cout<<"Iso changed"<<endl;
};