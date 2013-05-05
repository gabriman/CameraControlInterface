#include "CommandSetAperture.h"
#include "../camera/Camera.h"

CommandSetAperture::CommandSetAperture(Camera* camera1,const char* value, tinyxml2::XMLNode* node):Command(camera1,node){
	/*newValue=value;*/
	strcpy_s(newValue,value);
}

int CommandSetAperture::execute(){
	ResponseMsg response = camera->setProperty("APERTURE",newValue);
	OutputWriter::WriteToDoc(response,this->nodeOut,newValue);
	return response.getCode();
};