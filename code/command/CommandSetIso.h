#ifndef CommandSetIso_h
#define CommandSetIso_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

class CommandSetIso : public Command
{
private:
	char newValue[30];
public: 
	CommandSetIso (Camera* camera1, const char* value, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandSetIso_h */