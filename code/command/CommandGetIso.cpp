#include "CommandGetIso.h"

CommandGetIso::CommandGetIso(Camera* camera1):Command(camera1){}

CommandGetIso::CommandGetIso(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

int CommandGetIso::execute(){
	ResponseMsg response = camera->getProperty("ISO");
	OutputWriter::WriteToDoc(response,this->nodeOut);
	return 0;
}