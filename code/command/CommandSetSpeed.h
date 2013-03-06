#ifndef CommandSetSpeed_h
#define CommandSetSpeed_h


#include "../camera/Camera.h"
#include "Command.h"

class CommandSetSpeed : public Command
{
private:
	char newValue[30];
public: 
	CommandSetSpeed (Camera* camera1,const char* value);
	virtual void execute();
};

#endif /* CommandSetSpeed_h */