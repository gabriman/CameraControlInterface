//Prueba que realiza la escucha de modificacion de directorio

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

using namespace std;

void RefreshDirectory(LPTSTR);
void RefreshTree(LPTSTR);
void WatchDirectory(LPTSTR);


//This will be in a UTILS file
TCHAR* stringToTCHAR(std::string str){
	TCHAR *param=new TCHAR[str.size()+1];
	param[str.size()]=0;
	//As much as we'd love to, we can't use memcpy() because
	//sizeof(TCHAR)==sizeof(char) may not be true:
	std::copy(str.begin(),str.end(),param);
	return param;
}


void main(int argc, TCHAR *argv[])
{

	std::string directory;
	directory= "C:\\Users\\Gabry\\Documents\\APUNTES\\UGR\\PFC\\Pruebas\\pruebaNotifyNuevo\\dir";

	cout<<directory.c_str()<<endl;

	TCHAR * dirTCHAR = stringToTCHAR(directory);

	WatchDirectory(dirTCHAR);

}

void WatchDirectory(LPTSTR lpDir)
{
	DWORD dwWaitStatus; 
	HANDLE dwChangeHandles; 
	TCHAR lpDrive[4];
	TCHAR lpFile[_MAX_FNAME];
	TCHAR lpExt[_MAX_EXT];

	_tsplitpath_s(lpDir, lpDrive, 4, NULL, 0, lpFile, _MAX_FNAME, lpExt, _MAX_EXT);

	lpDrive[2] = (TCHAR)'\\';
	lpDrive[3] = (TCHAR)'\0';

	// Watch the directory for file creation and deletion. 

	dwChangeHandles = FindFirstChangeNotification( 
		lpDir,                         // directory to watch 
		FALSE,                         // do not watch subtree 
		FILE_NOTIFY_CHANGE_LAST_WRITE); // watch file name changes 

	if (dwChangeHandles == INVALID_HANDLE_VALUE) 
	{
		printf("\n ERROR: FindFirstChangeNotification function failed.\n");
		ExitProcess(GetLastError()); 
	}


	// Make a final validation check on our handles.

	if ((dwChangeHandles == NULL) )
	{
		printf("\n ERROR: Unexpected NULL from FindFirstChangeNotification.\n");
		ExitProcess(GetLastError()); 
	}

	// Change notification is set. Now wait on both notification 
	// handles and refresh accordingly. 

	while (TRUE) 
	{ 
		// Wait for notification.

		printf("\nWaiting for notification...\n");
		dwWaitStatus = WaitForSingleObject(dwChangeHandles, 
			INFINITE); 

		cout<<endl<<endl<<"--------------NUEVO CAMBIO------------"<<endl<<endl;

		switch (dwWaitStatus) 
		{ 
		case WAIT_OBJECT_0: 

			// A file was created, renamed, or deleted in the directory.
			// Refresh this directory and restart the notification.

			RefreshDirectory(lpDir); 
			if ( FindNextChangeNotification(dwChangeHandles) == FALSE )
			{
				printf("\n ERROR: FindNextChangeNotification function failed.\n");
				ExitProcess(GetLastError()); 
			}
			dwChangeHandles = FindFirstChangeNotification( 
				lpDir,                         // directory to watch 
				FALSE,                         // do not watch subtree 
				FILE_NOTIFY_CHANGE_LAST_WRITE); // watch file name changes 
			break; 


		case WAIT_TIMEOUT:

			// A timeout occurred, this would happen if some value other 
			// than INFINITE is used in the Wait call and no changes occur.
			// In a single-threaded environment you might not want an
			// INFINITE wait.

			printf("\nNo changes in the timeout period.\n");
			break;

		default: 
			printf("\n ERROR: Unhandled dwWaitStatus.\n");
			ExitProcess(GetLastError());
			break;
		}
	}
}

void RefreshDirectory(LPTSTR lpDir)
{
	// This is where you might place code to refresh your
	// directory listing, but not the subtree because it
	// would not be necessary.

	_tprintf(TEXT("Directory (%s) changed.\n"), lpDir);
}

void RefreshTree(LPTSTR lpDrive)
{
	// This is where you might place code to refresh your
	// directory listing, including the subtree.

	_tprintf(TEXT("Directory tree (%s) changed.\n"), lpDrive);
}

//
//
//
//void main()
//{
//
//
//
//	cout << "Hello World!" << endl;   cout << "Welcome to C++ Programming" << endl ;
//
//
//}