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
