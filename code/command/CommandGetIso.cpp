#include "CommandGetIso.h"

CommandGetIso::CommandGetIso(Camera* camera1):Command(camera1){}

CommandGetIso::CommandGetIso(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

void CommandGetIso::execute(){
	ResponseMsg response = camera->getProperty("ISO");
	OutputWriter::WriteToFile(response,this->nodeOut);
}