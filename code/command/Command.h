#ifndef Command_h
#define Command_h


#include "../camera/Camera.h"
#include "../tinyxml2_lib/tinyxml2.h"

class Command
{
protected:
	Camera* camera; //Camera command target
	tinyxml2::XMLDocument* docOut; //Document for write output
	tinyxml2::XMLNode* nodeOut; //Node for write output
public: 
	Command (Camera* c);
	Command (Camera* c, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node);
	virtual void execute(){};
};

#endif /* Command_h */