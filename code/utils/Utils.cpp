//
//Copyright 2013 Gabriel Rodríguez Rodríguez.
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.

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