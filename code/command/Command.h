#ifndef Command_h
#define Command_h

#include "../Camera.h"

class Command
{
protected:
	Camera* camera; //Camera command target
public: 
	Command (Camera* c);
	virtual void execute(){};
};

#endif /* Command_h */