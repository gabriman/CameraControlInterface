#include "CommandSetAperture.h"
#include "../camera/Camera.h"

CommandSetAperture::CommandSetAperture(Camera* camera1,const char* value):Command(camera1){
	/*newValue=value;*/
	strcpy(newValue,value);
}

void CommandSetAperture::execute(){
	cout<<"Ejecuting changeISO"<<endl;
	camera->setProperty("APERTURE",newValue);
	cout<<"Iso changed"<<endl;
};