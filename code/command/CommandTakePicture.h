#ifndef CommandTakePicture_h
#define CommandTakePicture_h


#include "../camera/Camera.h"
#include "Command.h"

class CommandTakePicture : public Command
{
public: 
	CommandTakePicture (Camera* camera1);
	virtual void execute();
};

#endif /* CommandTakePicture_h */