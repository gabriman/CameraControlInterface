#ifndef CommandSetIso_h
#define CommandSetIso_h


#include "../camera/Camera.h"
#include "Command.h"

class CommandSetIso : public Command
{
private:
	char newValue[30];
public: 
	CommandSetIso (Camera* camera1,const char* value);
	virtual void execute();
};

#endif /* CommandSetIso_h */