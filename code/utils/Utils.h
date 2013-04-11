#ifndef Utils_h
#define Utils_h

#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <map>

using namespace std;

class Utils {

public: 
	Utils() {}; //Constructor
	static TCHAR* stringToTCHAR(std::string str);
	static string convertInt(int number);
};
#endif /* Utils_h */