#include "CommandSetAperture.h"
#include "../camera/Camera.h"

CommandSetAperture::CommandSetAperture(Camera* camera1,const char* value, tinyxml2::XMLNode* node):Command(camera1,node){
	/*newValue=value;*/
	strcpy_s(newValue,value);
}

void CommandSetAperture::execute(){
	ResponseMsg response = camera->setProperty("APERTURE",newValue);
	OutputWriter::WriteToFile(response,this->nodeOut,newValue);
};