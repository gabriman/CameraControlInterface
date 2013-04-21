#ifndef CommandGetSpeed_h
#define CommandGetSpeed_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

class CommandGetSpeed : public Command
{
public: 
	CommandGetSpeed (Camera* camera1);
	CommandGetSpeed (Camera* camera1, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandGetSpeed_h */