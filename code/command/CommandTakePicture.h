#ifndef CommandTakePicture_h
#define CommandTakePicture_h


#include "../camera/Camera.h"
#include "Command.h"
#include "../tinyxml2_lib/tinyxml2.h"
#include "ResponseMsg.h"
#include "../OutputWriter.h"

class CommandTakePicture : public Command
{
public: 
	CommandTakePicture (Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandTakePicture_h */