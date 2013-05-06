#include "CommandGetSpeed.h"

CommandGetSpeed::CommandGetSpeed(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

int CommandGetSpeed::execute(){
	ResponseMsg response = camera->getProperty("SPEED");
	OutputWriter::WriteToDoc(response,this->nodeOut);
	return 0;
}