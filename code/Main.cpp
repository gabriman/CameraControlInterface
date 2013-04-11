//Prueba que realiza la escucha de modificacion de directorio

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
//#include "ttinyxml2.h"
#include "file_monitor\FileMonitor.h"
#include "command\CommandSetIso.h"
#include "command\CommandInit.h"
#include "command\CommandClose.h"
#include "camera\canon\CameraCanon.h"
#include "camera\nikon\CameraNikon.h"
#include "CommandCreator.h"
#include "tinyxml2_lib\tinyxml2.h"
#include "camera\canon\dictionary\DictionaryCanon.h"

using namespace std;

void main(int argc, TCHAR *argv[])
{
	/*	EdsUInt32 b;
	DictionaryCanon d;
	char* a = "30"; b = d.translate("SPEED",a);
	a = "25"; b = d.translate("SPEED",a);
	a = "20"; b = d.translate("SPEED",a);
	a = "15"; b = d.translate("SPEED",a);
	a = "13"; b = d.translate("SPEED",a);
	a = "10"; b = d.translate("SPEED",a);
	a = "8"; b = d.translate("SPEED",a);
	a = "6"; b = d.translate("SPEED",a);
	a = "5"; b = d.translate("SPEED",a);
	a = "4"; b = d.translate("SPEED",a);
	a = "3.2"; b = d.translate("SPEED",a);
	a = "3"; b = d.translate("SPEED",a);
	a = "2.5"; b = d.translate("SPEED",a);
	a = "2"; b = d.translate("SPEED",a);
	a = "1.6"; b = d.translate("SPEED",a);
	a = "1.6"; b = d.translate("SPEED",a);
	a = "0.4"; b = d.translate("SPEED",a);
	a = "0.3"; b = d.translate("SPEED",a);
	a = "1/4"; b = d.translate("SPEED",a);
	a = "1/5"; b = d.translate("SPEED",a);
	a = "1/1000"; b = d.translate("SPEED",a);
	a = "1/1250"; b = d.translate("SPEED",a);
	a = "1/1500"; b = d.translate("SPEED",a);
	a = "1/1600"; b = d.translate("SPEED",a);
	a = "1/2000"; b = d.translate("SPEED",a);
	a = "1/2500"; b = d.translate("SPEED",a);
	a = "1/3000"; b = d.translate("SPEED",a);
	a = "Bulb"; b = d.translate("SPEED",a);
	a = "bulba"; b = d.translate("SPEED",a);*/

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
