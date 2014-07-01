//
//Copyright 2013 Gabriel Rodríguez Rodríguez.
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.

/*
#define _CRTDBG_MAP_ALLOC //Debug memory leaks
#ifdef _DEBUG   
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) #define new DBG_NEW  
#endif
#endif  // _DEBUG*/

#include <stdlib.h>
//#include <crtdbg.h> //Debug memory leaks
#include <stdio.h>
#include <tchar.h>
#include "FileMonitor.h"
#include "CommandSetIso.h"
#include "CommandInit.h"
#include "CommandClose.h"
#include "CameraCanon.h"
#include "CameraNikon.h"
#include "CommandManager.h"
#include "tinyxml2.h"
#include "DictionaryCanon.h"
#include "Utils.h"

using namespace std;

bool TryStartCamera(Camera* camera, CommandManager* commandManager1, string cameraName);

int main(int argc, char *argv[])
{
	string exePath = Utils::getExeDir(argv[0]);
	string rootFolder = Utils::removeLastDir(exePath);

	string configFilePath = rootFolder;
	configFilePath.append("\\cfg\\config.xml");             //For execute from Debug or Release folder
	//configFilePath.append("cfg\\config.xml");             //For execute in root folder

	std::map<string,string> configTable = Utils::readConfigFiles(configFilePath);
	if (configTable.empty()) {cout<<"Error reading configuration file"<<endl; return -1;}
	std::string directoryIn,directoryOut;
	directoryIn = rootFolder; directoryIn.append("\\"); directoryIn.append(configTable.find("directoryIn")->second);
	directoryOut = rootFolder; directoryOut.append("\\");  directoryOut.append(configTable.find("directoryOut")->second);
	std::string fileIn = configTable.find("fileIn")->second;
	std::string fileOut = configTable.find("fileOut")->second;
	std::string photosDirectory = configTable.find("photosDirectory")->second;

	FileMonitor file_monitor(directoryIn);

	bool cameraLoaded = false;
	Camera* camera;
	CommandManager* commandManager1;

	//Detect if is a Canon camera
	if ((argv[1]==NULL && !cameraLoaded) || (argv[1]!=NULL && strcmp(argv[1],"canon")==0)){
		camera = new CameraCanon();
		commandManager1 = new CommandManager(camera,directoryIn,directoryOut,fileIn,fileOut);
		//Camera initialitation
		cameraLoaded = TryStartCamera(camera,commandManager1,"Canon");
	}

	//Detect if is a Nikon camera
	if ((argv[1]==NULL && !cameraLoaded) || (argv[1]!=NULL && strcmp(argv[1],"nikon")==0)){
		Camera* camera = new CameraNikon();
		commandManager1 = new CommandManager(camera,directoryIn,directoryOut,fileIn,fileOut);
		//Camera initialitation
		cameraLoaded = TryStartCamera(camera,commandManager1,"Nikon");
	}

	if (!cameraLoaded) exit(0);
	while(true){
		FileMonitor file_monitor(directoryIn);
		file_monitor.WatchDirectoryOneChange();  //Waiting until change in director
		list<Command*> commandsList = commandManager1->CreateCommandList();
		commandManager1->executeCommandList(commandsList);
		file_monitor.~FileMonitor();
	}
}

bool TryStartCamera(Camera* camera, CommandManager* commandManager1, string cameraName){
	//Camera initialitation
	Command* comandoinit = new CommandInit(camera);
	int error_init = comandoinit->execute();
	delete comandoinit;
	if (error_init<0){      //If error inicialitation camera, exit program
		cout<<"ERROR initiating camera "<<cameraName<<"\n"<<endl;
		Sleep(2000);
		delete commandManager1;
		delete camera;
		return false;
		//Delete CommandManager
	}
	else {
		cout<<"Camera "<<cameraName<<" loaded! \n\n"<<endl;
		return true;
	}
}