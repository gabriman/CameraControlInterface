#ifndef Utils_h
#define Utils_h
#define _SCL_SECURE_NO_WARNINGS	//Ignore warning in std::copy 

#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <map>
#include "EDSDKTypes.h"
#include <sstream>
#include "tinyxml2.h"

using namespace std;

class Utils {

public: 
	Utils() {}; //Constructor
	static TCHAR* stringToTCHAR(std::string str);
	static string convertInt(int number);
	static std::map<string,string> readConfigFiles(std::string pathFile);
	static Utils::string getExeDir(char* filepath);
	static Utils::string removeLastDir(std::string path);
};
#endif /* Utils_h */