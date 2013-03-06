#ifndef CommandCreator_h
#define CommandCreator_h

#include "tinyxml2_lib\tinyxml2.h"
#include "command\Command.h"
#include "camera\Camera.h"
#include <list>
#include "command\CommandSetIso.h"
#include "command\CommandSetSpeed.h"
#include "command\CommandSetAperture.h"

using namespace tinyxml2;

// Static class to create command's list from XML
class CommandCreator
{
public:
	Camera* camera;

public:
	CommandCreator(Camera* camera1);
	list<Command*> CreateCommandList(tinyxml2::XMLDocument* doc);
private:
	Command* createSetCommand(XMLNode* node);
	void createGetCommand(XMLNode* node);
	void createActionCommand(XMLNode* node);
};

#endif /* CommandCreator_h */