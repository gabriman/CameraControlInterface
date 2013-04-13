#include "CommandSetIso.h"
#include "../camera/Camera.h"

CommandSetIso::CommandSetIso(Camera* camera1,const char* value, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node):Command(camera1,doc,node){
	/*newValue=value;*/
	strcpy_s(newValue,value);
}

void CommandSetIso::execute(){
	ResponseMsg response = camera->setProperty("ISO",newValue);	
	OutputWriter::WriteToFile(response,this->nodeOut,newValue);
};