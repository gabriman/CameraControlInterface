#include "CommandGetAperture.h"

CommandGetAperture::CommandGetAperture(Camera* camera1):Command(camera1){}

CommandGetAperture::CommandGetAperture(Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node):Command(camera1,doc,node){}

using namespace tinyxml2;

void CommandGetAperture::execute(){
	char* value;
	camera->getProperty("APERTURE",&value);
	ResponseMsg response(MSG_OK,value);
	OutputWriter::WriteToFile(response,this->nodeOut);
}