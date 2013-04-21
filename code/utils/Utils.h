#ifndef Utils_h
#define Utils_h
#define _SCL_SECURE_NO_WARNINGS	//Ignore warning in std::copy 

#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <map>
#include "EDSDKTypes.h"
#include <sstream>

using namespace std;

class Utils {

public: 
	Utils() {}; //Constructor
	static TCHAR* stringToTCHAR(std::string str);
	static string convertInt(int number);
};
#endif /* Utils_h */