#ifndef FileMonitor_h
#define FileMonitor_h

#include <iostream>
#include <windows.h>
#include <tchar.h>

using namespace std;

class FileMonitor {

private:
	LPTSTR directoryUrl;
	DWORD dwWaitStatus; 
	HANDLE dwChangeHandles; 

public: 
	FileMonitor(std::string dir); //Constructor
	~FileMonitor(){}; //Destructor
	void WatchDirectoryOneChange();
private:
	void RefreshDirectory(LPTSTR lpDir);
	void RefreshTree(LPTSTR lpDrive);
};
#endif /* FileMonitor_h */