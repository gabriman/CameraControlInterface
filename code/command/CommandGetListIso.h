#ifndef CommandGetListIso_h
#define CommandGetListIso_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

class CommandGetListIso : public Command
{
public: 
	CommandGetListIso (Camera* camera1);
	CommandGetListIso (Camera* camera1, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandGetListIso_h */