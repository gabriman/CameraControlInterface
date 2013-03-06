#include "CommandTakePicture.h"
#include "../camera/Camera.h"

CommandTakePicture::CommandTakePicture(Camera* camera1):Command(camera1){}

void CommandTakePicture::execute(){
	camera->takePicture();
};