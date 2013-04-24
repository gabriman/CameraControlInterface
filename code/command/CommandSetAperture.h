#ifndef CommandSetAperture_h
#define CommandSetAperture_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

class CommandSetAperture : public Command
{
private:
	char newValue[30];
public: 
	CommandSetAperture (Camera* camera1, const char* value, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandSetAperture_h */