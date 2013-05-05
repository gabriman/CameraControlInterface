#include "CommandGetListAperture.h"

CommandGetListAperture::CommandGetListAperture(Camera* camera1):Command(camera1){}

CommandGetListAperture::CommandGetListAperture(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

using namespace tinyxml2;

int CommandGetListAperture::execute(){
	ResponseMsg response = camera->getGetList("APERTURE");
	OutputWriter::WriteToDoc(response,this->nodeOut);
	return 0;
}