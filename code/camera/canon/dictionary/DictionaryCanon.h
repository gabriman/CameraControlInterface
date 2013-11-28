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

#ifndef DictionaryCanon_h
#define DictionaryCanon_h

#include <map>
#include "EDSDKTypes.h"


using namespace std;

// Static class to create command's list from XML
class DictionaryCanon
{
private:
	struct cmp_str {  bool operator()(const char* a, const char* b) const {
		return std::strcmp(a, b) > 0;} 
	};

	std::map<EdsUInt32, const char *> _propertyTableISOEds;
	std::map<const char *, EdsUInt32,cmp_str> _propertyTableISOString;

	std::map<EdsUInt32, const char *> _propertyTableSpeedEds;	
	std::map<const char *, EdsUInt32,cmp_str> _propertyTableSpeedString;

	std::map<EdsUInt32, const char *> _propertyTableApertureEds;	
	std::map<const char *, EdsUInt32,cmp_str> _propertyTableApertureString;

public:
	DictionaryCanon();
	const char * translate(string prop,EdsUInt32 value);
	EdsUInt32 translate(string prop,const char * value);


private:
	void createIsoTable();
	void createSpeedTable();
	void createAvTable();
	//	static void createSetCommand(XMLNode* node);
	//	static void createGetCommand(XMLNode* node);
	//	static void createActionCommand(XMLNode* node);
};

#endif /* DictionaryCanon_h */