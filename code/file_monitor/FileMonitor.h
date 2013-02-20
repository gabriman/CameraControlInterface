#ifndef FileMonitor_h
#define FileMonitor_h

#include <iostream>
#include <windows.h>
#include <tchar.h>

using namespace std;

class FileMonitor {

private:
	// Datos miembro de la clase "pareja"
	LPTSTR directoryUrl;

public: 
	FileMonitor(std::string dir); //Constructor
	~FileMonitor(){}; //Destructor
	void WatchDirectory();
private:
	void RefreshDirectory(LPTSTR lpDir);
	void RefreshTree(LPTSTR lpDrive);
};
#endif /* FileMonitor_h */