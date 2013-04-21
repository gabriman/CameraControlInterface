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

void main(int argc, TCHAR *argv[])
{
	std::string directoryIn,directoryOut;
	directoryIn = "./cfg/in";
	directoryOut = "./cfg/out";
	std::string fileIn= "inputfile.xml";
	std::string fileOut= "outputfile.xml";

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
			(*i)->execute();
	}
	Command* comandoclose = new CommandClose(cameraCanon1);
}
