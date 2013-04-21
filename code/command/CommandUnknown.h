#ifndef CommandUnknown_h
#define CommandUnknown_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

class CommandUnknown : public Command
{
public: 
	CommandUnknown (Camera* camera1, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandUnknown_h */