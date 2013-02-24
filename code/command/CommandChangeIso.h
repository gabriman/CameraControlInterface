#ifndef CommandChangeIso_h
#define CommandChangeIso_h


#include "../camera/Camera.h"
#include "Command.h"

class CommandChangeIso : public Command
{
public: 
	CommandChangeIso (Camera* camera);
	virtual void execute();
};

#endif /* CommandChangeIso_h */