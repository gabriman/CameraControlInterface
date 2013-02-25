#ifndef CommandCreator_h
#define CommandCreator_h

#include "tinyxml2_lib\tinyxml2.h"
#include "command\Command.h"
#include <list>

using namespace std;

// Static class to create command's list from XML
class CommandCreator
{
public:
	static list<Command> CreateCommandList(tinyxml2::XMLDocument);
};

#endif /* CommandCreator_h */