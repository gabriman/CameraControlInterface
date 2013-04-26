//Prueba que realiza la escucha de modificacion de directorio

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include "FileMonitor.h"
#include "CommandSetIso.h"
#include "CommandInit.h"
#include "CommandClose.h"
#include "CameraCanon.h"
#include "CameraNikon.h"
#include "CommandCreator.h"
#include "tinyxml2.h"
#include "DictionaryCanon.h"
#include "Utils.h"

using namespace std;

int main(int argc, char *argv[])
{
	string exePath = Utils::getExeDir(argv[0]);
	string rootFolder = Utils::removeLastDir(exePath);

	string configFilePath = rootFolder;
	configFilePath.append("\\cfg\\config.xml");		//For execute from Debug or Release folder
	//configFilePath.append("cfg\\config.xml");		//For execute in root folder

	std::map<string,string> configTable = Utils::readConfigFiles(configFilePath);
	if (configTable.empty()) {cout<<"Error reading configuration file"<<endl; return -1;}
	std::string directoryIn,directoryOut;
	directoryIn = rootFolder; directoryIn.append("\\"); directoryIn.append(configTable.find("directoryIn")->second);
	directoryOut = rootFolder; directoryOut.append("\\");  directoryOut.append(configTable.find("directoryOut")->second);
	std::string fileIn = configTable.find("fileIn")->second;
	std::string fileOut = configTable.find("fileOut")->second;

	FileMonitor file_monitor(directoryIn);

	//Camera initialitation
	Camera* cameraCanon1 = new CameraCanon();
	Command* comandoinit = new CommandInit(cameraCanon1);
	comandoinit->execute();

	CommandCreator commandCreator(cameraCanon1,directoryIn,directoryOut,fileIn,fileOut);
	while(true){
		file_monitor.WatchDirectoryOneChange();  //Waiting until change
		//Try to create a XMLDocument from file

		list<Command*> commandsList = commandCreator.CreateCommandList();

		for (list<Command*>::iterator i = commandsList.begin(); i != commandsList.end(); i++)
			if ((*i)->execute()<0) break;   //Execute and if return error, stop to execute commands
	}
	Command* comandoclose = new CommandClose(cameraCanon1);
}
