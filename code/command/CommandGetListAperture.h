#ifndef CommandGetListAperture_h
#define CommandGetListAperture_h


#include "../camera/Camera.h"
#include "Command.h"
#include "../tinyxml2_lib/tinyxml2.h"
#include "ResponseMsg.h"
#include "../OutputWriter.h"

class CommandGetListAperture : public Command
{
public: 
	CommandGetListAperture (Camera* camera1);
	CommandGetListAperture (Camera* camera1, tinyxml2::XMLNode* node);
	virtual void execute();
};

#endif /* CommandGetListAperture_h */