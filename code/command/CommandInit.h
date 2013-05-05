#ifndef CommandInit_h
#define CommandInit_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

class CommandInit : public Command
{
public: 
	CommandInit (Camera* camera);
	virtual int execute();
};

#endif /* CommandInit_h */