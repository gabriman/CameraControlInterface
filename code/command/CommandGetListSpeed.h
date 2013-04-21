#ifndef CommandGetListSpeed_h
#define CommandGetListSpeed_h


#include "../camera/Camera.h"
#include "Command.h"
#include "../tinyxml2_lib/tinyxml2.h"
#include "ResponseMsg.h"
#include "../OutputWriter.h"

class CommandGetListSpeed : public Command
{
public: 
	CommandGetListSpeed (Camera* camera1);
	CommandGetListSpeed (Camera* camera1, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandGetListSpeed_h */