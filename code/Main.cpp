//Prueba que realiza la escucha de modificacion de directorio

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
//#include "ttinyxml2.h"
#include "file_monitor\FileMonitor.h"
#include "command\CommandChangeIso.h"
#include "command\CommandInit.h"
#include "command\CommandClose.h"
#include "camera\canon\CameraCanon.h"
#include "camera\nikon\CameraNikon.h"
#include "CommandCreator.h"
#include "tinyxml2_lib\tinyxml2.h"
#include "camera\canon\dictionary\DictionaryCanon.h" //PRUEBA, LUEGO BORRAR


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

	//Try to create a XMLDocument from file
	tinyxml2::XMLDocument* docXML = CreateXMLDocument(directory,file);
	if (docXML->Error()==true){
		cout<<"Error opening "<<file.data()<<" file"<<endl;
		return;
	}
	else cout<<"File "<<file.data()<<" opened OK "<<endl;

	
	Camera* camera = new CameraCanon();

	CommandCreator::CreateCommandList(camera, docXML);


	FileMonitor file_monitor(directory);
	
	Camera* cameraCanon1 = new CameraCanon();
	Command* comando1 = new CommandInit(cameraCanon1);
	comando1->execute();

	//while(true){
		//file_monitor.WatchDirectoryOneChange();

		Sleep(1000);
		Command* comando = new CommandChangeIso(cameraCanon1,"400");
		comando->execute();
		Sleep(1000);
	//}
	
	Command* comando2 = new CommandClose(cameraCanon1);

}
