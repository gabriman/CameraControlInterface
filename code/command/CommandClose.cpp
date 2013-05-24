#include "CommandClose.h"
#include "../camera/Camera.h"

CommandClose::CommandClose(Camera* camera1):Command(camera1){}

int CommandClose::execute(){
	ResponseMsg response = camera->close();
	OutputWriter::WriteCloseOutput(response);
	exit(0);
	return 0;
};