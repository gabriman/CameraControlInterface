#include "CommandSetSpeed.h"
#include "../camera/Camera.h"

CommandSetSpeed::CommandSetSpeed(Camera* camera1,const char* value, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node):Command(camera1,doc,node){
	/*newValue=value;*/
	strcpy_s(newValue,value);
}

void CommandSetSpeed::execute(){
	ResponseMsg response = camera->setProperty("SPEED",newValue);
	OutputWriter::WriteToFile(response,this->nodeOut,newValue);
};