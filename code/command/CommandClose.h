#ifndef CommandClose_h
#define CommandClose_h


#include "../camera/Camera.h"
#include "Command.h"

class CommandClose : public Command
{
public: 
	CommandClose (Camera* camera);
	virtual void execute();
};

#endif /* CommandClose_h */