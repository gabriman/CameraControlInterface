#ifndef FileMonitor_h
#define FileMonitor_h

#include <iostream>
#include <windows.h>
#include <tchar.h>

using namespace std;

/**********************************************************************************************//**
 * @brief	File monitor for notify changes in a directory.
 **************************************************************************************************/
class FileMonitor {

private:
	LPTSTR directoryUrl;
	DWORD dwWaitStatus; 
	HANDLE dwChangeHandles; 

public: 

	/**********************************************************************************************//**
	 * @brief	Constructor.
	 *
	 * @param	dir	The directory to be monitored
	 **************************************************************************************************/
	FileMonitor(std::string dir); //Constructor

	/**********************************************************************************************//**
	 * @brief	Destructor.
	 **************************************************************************************************/
	~FileMonitor(){};

	/**********************************************************************************************//**
	 * @brief	Watch changes in a directory
	 * @details The process will be waiting until a change in a file of the directory occurs
	 **************************************************************************************************/
	void WatchDirectoryOneChange();
private:

	/**********************************************************************************************//**
	 * @brief	Refresh directory.
	 *
	 * @param	lpDir	The dir.
	 **************************************************************************************************/
	void RefreshDirectory(LPTSTR lpDir);

	/**********************************************************************************************//**
	 * @brief	Refresh tree.
	 *
	 * @param	lpDrive	The drive.
	 **************************************************************************************************/
	void RefreshTree(LPTSTR lpDrive);
};
#endif /* FileMonitor_h */