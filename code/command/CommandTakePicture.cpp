#include "CommandTakePicture.h"
#include "../camera/Camera.h"

CommandTakePicture::CommandTakePicture(Camera* camera1, tinyxml2::XMLNode* node):Command(camera1,node){}

int CommandTakePicture::execute(){
	ResponseMsg response = camera->takePicture();
	OutputWriter::WriteToDoc(response,this->nodeOut);
	return response.getCode();
};