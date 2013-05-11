#include "Utils.h"

using namespace std;

//This will be in a UTILS file
TCHAR* Utils::stringToTCHAR(std::string str){
	TCHAR *param=new TCHAR[str.size()+1];
	param[str.size()]=0;
	//As much as we'd love to, we can't use memcpy() because
	//sizeof(TCHAR)==sizeof(char) may not be true:
	std::copy(str.begin(),str.end(),param);
	return param;
}

string Utils::convertInt(int number)
{
	std::stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}

string Utils::removeLastDir(std::string path){
	int pos = -1;
	pos = path.find_last_of('\\');
	if (pos==-1) path.find_last_of('/');
	path.resize(pos);
	while (path.at(path.size()-1)=='\\')
		path.resize(path.size()-1);
	return path;
}

string Utils::getExeDir(char* filepath) {
	string s = string(filepath);
	s = Utils::removeLastDir(filepath);
	return s;
}



std::map<string,string> Utils::readConfigFiles(std::string pathFile)
{	
	std::map<string,string> configTable;
	try{
		tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument;
		doc->LoadFile(pathFile.data());
		if (doc->Error()) return configTable;
		tinyxml2::XMLNode* rootConfig = doc->FirstChildElement("config");
		tinyxml2::XMLNode* directoryInNode = rootConfig->FirstChildElement("directoryIn");
		if (directoryInNode->FirstChild()->Value()!="") configTable.insert( std::pair<string, string>("directoryIn",directoryInNode->FirstChild()->Value()));
		tinyxml2::XMLNode* directoryOutNode  = rootConfig->FirstChildElement("directoryOut");
		if (directoryOutNode->FirstChild()->Value()!="") configTable.insert(std::pair<string, string>("directoryOut",directoryOutNode->FirstChild()->Value()));
		tinyxml2::XMLNode* fileInNode  = rootConfig->FirstChildElement("fileIn");
		if (fileInNode->FirstChild()->Value()!="") configTable.insert(std::pair<string, string>("fileIn",fileInNode->FirstChild()->Value()));
		tinyxml2::XMLNode* fileOutNode  = rootConfig->FirstChildElement("fileOut");
		if (fileOutNode->FirstChild()->Value()!="") configTable.insert(std::pair<string, string>("fileOut",fileOutNode->FirstChild()->Value()));
		tinyxml2::XMLNode* photosDirNode  = rootConfig->FirstChildElement("photosDirectory");
		if (photosDirNode->FirstChild()->Value()!="") configTable.insert(std::pair<string, string>("photosDirectory",photosDirNode->FirstChild()->Value()));
	}
	catch (...) {
		cout << "An exception occurred opening config file"<< endl;
		configTable.clear();
	}
	return configTable;
}