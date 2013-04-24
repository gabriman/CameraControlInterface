#ifndef Command_h
#define Command_h


#include "Camera.h"
#include "tinyxml2.h"
class Command
{
protected:
	Camera* camera; //Camera command target
	tinyxml2::XMLNode* nodeOut; //Node for write output
public: 
	Command (Camera* c);
	Command (Camera* c, tinyxml2::XMLNode* node);
	virtual int execute(){return -1;};
};

#endif /* Command_h */