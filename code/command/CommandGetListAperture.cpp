#include "CommandGetListAperture.h"

CommandGetListAperture::CommandGetListAperture(Camera* camera1):Command(camera1){}

CommandGetListAperture::CommandGetListAperture(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

void CommandGetListAperture::execute(){
	ResponseMsg response = camera->getGetList("APERTURE");
	OutputWriter::WriteToFile(response,this->nodeOut);
}