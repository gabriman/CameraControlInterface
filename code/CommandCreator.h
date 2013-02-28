#ifndef CommandCreator_h
#define CommandCreator_h

#include "tinyxml2_lib\tinyxml2.h"
#include "command\Command.h"
#include "camera\Camera.h"
#include <list>

using namespace tinyxml2;

// Static class to create command's list from XML
class CommandCreator
{
public:
	Camera* camera;

public:
	static list<Command> CreateCommandList(Camera* camera,tinyxml2::XMLDocument* doc);
private:
	static void createSetCommand(XMLNode* node);
	static void createGetCommand(XMLNode* node);
	static void createActionCommand(XMLNode* node);
};

#endif /* CommandCreator_h */