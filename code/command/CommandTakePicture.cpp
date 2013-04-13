#include "CommandTakePicture.h"
#include "../camera/Camera.h"

CommandTakePicture::CommandTakePicture(Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node):Command(camera1,doc,node){}

void CommandTakePicture::execute(){
	ResponseMsg response = camera->takePicture();
	OutputWriter::WriteToFile(response,this->nodeOut);
};