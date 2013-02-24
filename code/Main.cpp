//Prueba que realiza la escucha de modificacion de directorio

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
//#include "ttinyxml2.h"
#include "file_monitor\FileMonitor.h"
#include "command\CommandChangeIso.h"

using namespace std;


void main(int argc, TCHAR *argv[])
{

	std::string directory;
	directory= "C:\\Users\\Gabry\\Documents\\APUNTES\\UGR\\PFC\\Pruebas\\pruebaNotifyNuevo\\dir";

	FileMonitor file_monitor(directory);

	while(true){
		file_monitor.WatchDirectoryOneChange();

		Camera camera1;

		Command* comando1 = new CommandChangeIso(&camera1);
		comando1->execute();
	}

}

