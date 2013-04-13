#include "CommandUnknown.h"

using namespace tinyxml2;


CommandUnknown::CommandUnknown(Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node):Command(camera1,doc,node){}

void CommandUnknown::execute(){
	ResponseMsg response(CAMERROR_COMMAND_FORMAT_ERROR,"Command with incorrect format");
	OutputWriter::WriteToFile(response,this->nodeOut);
}