#ifndef CommandSetAperture_h
#define CommandSetAperture_h


#include "../camera/Camera.h"
#include "Command.h"
#include "../OutputWriter.h"

class CommandSetAperture : public Command
{
private:
	char newValue[30];
public: 
	CommandSetAperture (Camera* camera1, const char* value, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandSetAperture_h */