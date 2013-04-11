#ifndef CommandGetIso_h
#define CommandGetIso_h


#include "../camera/Camera.h"
#include "Command.h"
#include "../tinyxml2_lib/tinyxml2.h"
#include "ResponseMsg.h"
#include "../OutputWriter.h"

class CommandGetIso : public Command
{
public: 
	CommandGetIso (Camera* camera1);
	CommandGetIso (Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandGetIso_h */