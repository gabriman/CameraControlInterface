#ifndef CommandGetAperture_h
#define CommandGetAperture_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

class CommandGetAperture : public Command
{
public: 
	CommandGetAperture (Camera* camera1);
	CommandGetAperture (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandGetAperture_h */