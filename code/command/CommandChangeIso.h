#ifndef CommandChangeIso_h
#define CommandChangeIso_h


#include "../camera/Camera.h"
#include "Command.h"

class CommandChangeIso : public Command
{
private:
	char newValue[30];
public: 
	CommandChangeIso (Camera* camera1,const char* value);
	virtual void execute();
};

#endif /* CommandChangeIso_h */