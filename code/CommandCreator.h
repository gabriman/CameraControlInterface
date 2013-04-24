#ifndef CommandCreator_h
#define CommandCreator_h

#include "tinyxml2.h"
#include "Command.h"
#include "Camera.h"
#include <list>
#include "CommandSetIso.h"
#include "CommandSetSpeed.h"
#include "CommandSetAperture.h"
#include "CommandTakePicture.h"
#include "CommandGetIso.h"
#include "CommandGetSpeed.h"
#include "CommandGetAperture.h"
#include "CommandUnknown.h"
#include "CommandGetListIso.h"
#include "CommandGetListAperture.h"
#include "CommandGetListSpeed.h"
#include "CommandClose.h"
#include <iostream>
#include <fstream>

#define MAX_ATTEMPTS_LOAD_FILES 20

using namespace tinyxml2;

// Static class to create command's list from XML
class CommandCreator
{
public:
	Camera* camera;
private:
	static std::string directoryIn;
	static std::string directoryOut;
	static std::string pathFileIn;
	static std::string pathFileOut;
	static tinyxml2::XMLDocument* docIn;
	static tinyxml2::XMLDocument* docOut;

public:
	CommandCreator(Camera* camera1, std::string dirIn, std::string dirOut, std::string fIn, std::string fOut);
	list<Command*> CreateCommandList();
	static tinyxml2::XMLDocument* getDocOut();
	static std::string getPathOut();
private:
	int loadXMLFromFiles();
	Command* createSetCommand(XMLNode* node);
	Command* createGetCommand(XMLNode* node);
	Command* createGetListCommand(XMLNode* node);
	Command* createActionCommand(XMLNode* node);
	Command* createUnknownCommand(XMLNode* node);
	Command* createCloseCommand();
	tinyxml2::XMLDocument* CreateXMLDocument(std::string directory, std::string file, bool out = false);
};

#endif /* CommandCreator_h */