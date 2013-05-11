#include "CommandSetTargetSave.h"
#include "../camera/Camera.h"

CommandSetTargetSave::CommandSetTargetSave(Camera* camera1, std::string target, std::string path, tinyxml2::XMLNode* node):Command(camera1,node){
	this->target = string(target);
	this->path = string(path);
}

int CommandSetTargetSave::execute(){
	//TODO Check path
	if (!path.empty() || !this->target.compare("camera"))
	{
		camera->setTargetPhotos(target);
		camera->setPathSavePhotos(path);	//If path have value, set. If is empty, hold previous path
		ResponseMsg response = camera->setTargetSave();
		OutputWriter::WriteToDoc(response,this->nodeOut);
		return response.getCode();
	}
	else{	//If the target is not camera and the path is empty (path not provided and not default path)
		ResponseMsg response = ResponseMsg(CAMERROR_VALUE_UNKNOWN,"There isn't directory to save the images");
		OutputWriter::WriteToDoc(response,this->nodeOut);
		return response.getCode();
	}
};