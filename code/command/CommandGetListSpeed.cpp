#include "CommandGetListSpeed.h"

CommandGetListSpeed::CommandGetListSpeed(Camera* camera1):Command(camera1){}

CommandGetListSpeed::CommandGetListSpeed(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

int CommandGetListSpeed::execute(){
	ResponseMsg response = camera->getGetList("SPEED");
	OutputWriter::WriteToDoc(response,this->nodeOut);
	return 0;
}