#ifndef CommandCreator_h
#define CommandCreator_h

#include "tinyxml2_lib\tinyxml2.h"
#include "command\Command.h"
#include "camera\Camera.h"
#include <list>
#include "command\CommandSetIso.h"
#include "command\CommandSetSpeed.h"
#include "command\CommandSetAperture.h"
#include "command\CommandTakePicture.h"
#include "command\CommandGetIso.h"
#include <iostream>
#include <fstream>

using namespace tinyxml2;

// Static class to create command's list from XML
class CommandCreator
{
public:
	Camera* camera;
private:
	static std::string directoryIn;
	static std::string directoryOut;
	static std::string fileIn;
	static std::string fileOut;
	static tinyxml2::XMLDocument* docIn;
	static tinyxml2::XMLDocument* docOut;

public:
	CommandCreator(Camera* camera1, std::string dirIn, std::string dirOut, std::string fIn, std::string fOut);
	list<Command*> CreateCommandList();
	static tinyxml2::XMLDocument* getDocOut();
	static std::string getPathOut();
private:
	void loadXMLFromFiles();
	Command* createSetCommand(XMLNode* node);
	Command* createGetCommand(XMLNode* node);
	Command* createActionCommand(XMLNode* node);
	tinyxml2::XMLDocument* CreateXMLDocument(std::string directory, std::string file, bool out = false);
};

#endif /* CommandCreator_h */