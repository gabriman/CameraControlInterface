#ifndef CommandUnknown_h
#define CommandUnknown_h


#include "../camera/Camera.h"
#include "Command.h"
#include "../tinyxml2_lib/tinyxml2.h"
#include "ResponseMsg.h"
#include "../OutputWriter.h"

class CommandUnknown : public Command
{
public: 
	CommandUnknown (Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandUnknown_h */