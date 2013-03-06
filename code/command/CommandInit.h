#ifndef CommandInit_h
#define CommandInit_h


#include "../camera/Camera.h"
#include "Command.h"

class CommandInit : public Command
{
public: 
	CommandInit (Camera* camera);
	virtual void execute();
};

#endif /* CommandInit_h */