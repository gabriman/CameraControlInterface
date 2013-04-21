#include "CommandGetAperture.h"

CommandGetAperture::CommandGetAperture(Camera* camera1):Command(camera1){}

CommandGetAperture::CommandGetAperture(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

void CommandGetAperture::execute(){
	ResponseMsg response = camera->getProperty("APERTURE");
	OutputWriter::WriteToFile(response,this->nodeOut);
}