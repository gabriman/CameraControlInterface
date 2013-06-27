#include <stdlib.h>
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

		//int cameraLoaded = false;
		//Camera* camera;

		//CommandManager commandManager1;
		//if ((argv[1]==NULL && !cameraLoaded) || (argv[1]!=NULL && strcmp(argv[1],"canon")==0)){
		//	camera = new CameraCanon();
		//	CommandManager commandManager1 = CommandManager(camera,directoryIn,directoryOut,fileIn,fileOut);
		//	//Camera initialitation
		//	Command* comandoinit = new CommandInit(camera);
		//	int error_init = comandoinit->execute();
		//	if (error_init<0){      //If error inicialitation camera, exit program
		//			cout<<"ERROR inicialitation camera Canon"<<endl;
		//			Sleep(2000);
		//			//Delete CommandManager
		//	}
		//	else {
		//		cout<<"Cargada cámara Canon\n"<<endl;
		//		cameraLoaded=true;
		//	}

		//}

		//if ((argv[1]==NULL && !cameraLoaded) || (argv[1]!=NULL && strcmp(argv[1],"nikon")==0)){
		//	Camera* camera = new CameraNikon();
		//	CommandManager commandManager1 = CommandManager(camera,directoryIn,directoryOut,fileIn,fileOut);
		//	//Camera initialitation
		//	Command* comandoinit = new CommandInit(camera);
		//	int error_init = comandoinit->execute();
		//	if (error_init<0){      //If error inicialitation camera, exit program
		//			cout<<"ERROR inicialitation camera Nikon"<<endl;
		//			Sleep(2000);
		//			//Delete CommandManager
		//	}
		//	else {
		//		cout<<"Cargada cámara Nikon\n"<<endl;
		//		cameraLoaded=true;
		//	}
		//}
  //      
		//if (!cameraLoaded) exit(0);


		////LO DE ANTES
		////Camera* cameraCanon1 = new CameraCanon(photosDirectory);
		//Camera* cameraCanon1 = new CameraNikon();
  //      //CameraCanon* cameraCanon1 = new CameraCanon();
  //      CommandManager commandManager1(cameraCanon1,directoryIn,directoryOut,fileIn,fileOut);

  //      //Camera initialitation
  //      Command* comandoinit = new CommandInit(cameraCanon1);
  //      int error_init = comandoinit->execute();
  //      if (error_init<0){      //If error inicialitation camera, exit program
  //              cout<<"ERROR inicialitation camera"<<endl;
  //              exit(0);
  //      }



        //cameraCanon1->downloadLastImage();

		int cameraLoaded = false;
		Camera* camera;
		CommandManager* commandManager1;

		if ((argv[1]==NULL && !cameraLoaded) || (argv[1]!=NULL && strcmp(argv[1],"canon")==0)){
			camera = new CameraCanon();
			commandManager1 = new CommandManager(camera,directoryIn,directoryOut,fileIn,fileOut);
			//Camera initialitation
			Command* comandoinit = new CommandInit(camera);
			int error_init = comandoinit->execute();
			if (error_init<0){      //If error inicialitation camera, exit program
					cout<<"ERROR inicialitation camera Canon"<<endl;
					Sleep(2000);
					//Delete CommandManager
			}
			else {
				cout<<"Cargada cámara Canon\n"<<endl;
				cameraLoaded=true;
			}

		}

		if ((argv[1]==NULL && !cameraLoaded) || (argv[1]!=NULL && strcmp(argv[1],"nikon")==0)){
			Camera* camera = new CameraNikon();
			commandManager1 = new CommandManager(camera,directoryIn,directoryOut,fileIn,fileOut);
			//Camera initialitation
			Command* comandoinit = new CommandInit(camera);
			int error_init = comandoinit->execute();
			if (error_init<0){      //If error inicialitation camera, exit program
					cout<<"ERROR inicialitation camera Nikon"<<endl;
					Sleep(2000);
					//Delete CommandManager
			}
			else {
				cout<<"Cargada cámara Nikon\n"<<endl;
				cameraLoaded=true;
			}
		}
        
		if (!cameraLoaded) exit(0);

        while(true){
                file_monitor.WatchDirectoryOneChange();  //Waiting until change in directory
                //Sleep(1000);

                list<Command*> commandsList = commandManager1->CreateCommandList();
                commandManager1->executeCommandList(commandsList);
        }
        //Command* comandoclose = new CommandClose(camera);
}