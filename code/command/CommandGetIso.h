#ifndef CommandGetIso_h
#define CommandGetIso_h


#include "../camera/Camera.h"
#include "Command.h"
#include "../CommandCreator.h"

class CommandGetIso : public Command
{
public: 
	CommandGetIso (Camera* camera1);
	CommandGetIso (Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandGetIso_h */