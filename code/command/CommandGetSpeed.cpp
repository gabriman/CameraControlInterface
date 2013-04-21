#include "CommandGetSpeed.h"

CommandGetSpeed::CommandGetSpeed(Camera* camera1):Command(camera1){}

CommandGetSpeed::CommandGetSpeed(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

void CommandGetSpeed::execute(){
	ResponseMsg response = camera->getProperty("SPEED");
	OutputWriter::WriteToFile(response,this->nodeOut);
}