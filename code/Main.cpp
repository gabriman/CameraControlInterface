//Prueba que realiza la escucha de modificacion de directorio

#include <iostream>
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

//XMLDocument
tinyxml2::XMLDocument* CreateXMLDocument(std::string directory, std::string file){
	std::string completePath = directory.append("/");
	completePath = completePath.append(file);
	cout<<completePath.c_str()<<endl;

	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument;
	doc->LoadFile(completePath.data());

	return doc;
}

void main(int argc, TCHAR *argv[])
{
	EdsUInt32 b;
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
	a = "1/10000"; b = d.translate("SPEED",a);
	a = "bulb"; b = d.translate("SPEED",a);

	std::string directory;
	directory= "./cfg";
	std::string file= "inputfile.xml";

	FileMonitor file_monitor(directory);

	Camera* cameraCanon1 = new CameraCanon();
	Command* comando1 = new CommandInit(cameraCanon1);
	comando1->execute();


	CommandCreator comandCreator(cameraCanon1);
	while(true){
		file_monitor.WatchDirectoryOneChange();

		//Try to create a XMLDocument from file
		tinyxml2::XMLDocument* docXML = CreateXMLDocument(directory,file);
		if (docXML->Error()==true){
			cout<<"Error opening "<<file.data()<<" file"<<endl;
			return;
		}
		else cout<<"File "<<file.data()<<" opened OK "<<endl;

		list<Command*> commandsList = comandCreator.CreateCommandList(docXML);

		for (list<Command*>::iterator i = commandsList.begin(); i != commandsList.end(); i++)
		{
			(*i)->execute();
		}
		//comando->execute();
		//Sleep(1000);
	}

	Command* comando2 = new CommandClose(cameraCanon1);

}
