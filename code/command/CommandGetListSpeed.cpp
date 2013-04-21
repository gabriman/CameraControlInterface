#include "CommandGetListSpeed.h"

CommandGetListSpeed::CommandGetListSpeed(Camera* camera1):Command(camera1){}

CommandGetListSpeed::CommandGetListSpeed(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

void CommandGetListSpeed::execute(){
	ResponseMsg response = camera->getGetList("SPEED");
	OutputWriter::WriteToFile(response,this->nodeOut);
}