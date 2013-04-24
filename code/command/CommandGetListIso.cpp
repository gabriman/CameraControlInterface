#include "CommandGetListIso.h"

CommandGetListIso::CommandGetListIso(Camera* camera1):Command(camera1){}

CommandGetListIso::CommandGetListIso(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

int CommandGetListIso::execute(){
	ResponseMsg response = camera->getGetList("ISO");
	OutputWriter::WriteToFile(response,this->nodeOut);
	return 0;
}