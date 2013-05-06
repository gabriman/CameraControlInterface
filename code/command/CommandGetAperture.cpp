#include "CommandGetAperture.h"

CommandGetAperture::CommandGetAperture(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

int CommandGetAperture::execute(){
	ResponseMsg response = camera->getProperty("APERTURE");
	OutputWriter::WriteToDoc(response,this->nodeOut);
	return 0;
}