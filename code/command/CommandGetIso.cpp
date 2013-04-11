#include "CommandGetIso.h"

CommandGetIso::CommandGetIso(Camera* camera1):Command(camera1){}

CommandGetIso::CommandGetIso(Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node):Command(camera1,doc,node){}

using namespace tinyxml2;

void CommandGetIso::execute(){
	char* value;
	camera->getProperty("ISO",&value);
	ResponseMsg response(MSG_OK,value);
	OutputWriter::WriteToFile(response,this->nodeOut);
}