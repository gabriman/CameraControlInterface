#ifndef DictionaryCanon_h
#define DictionaryCanon_h

#include <map>
#include "EDSDKTypes.h"


using namespace std;

// Static class to create command's list from XML
class DictionaryCanon
{
private:
	std::map<EdsUInt32, const char *> _propertyTableISOEds;
	std::map<const char *, EdsUInt32> _propertyTableISOString;

	std::map<EdsUInt32, const char *> _propertyTableSpeedEds;	
	std::map<const char *, EdsUInt32> _propertyTableSpeedString;

	std::map<EdsUInt32, const char *> _propertyTableAvEds;	
	std::map<const char *, EdsUInt32> _propertyTableAvString;

public:
	DictionaryCanon();
	const char * translate(string property,EdsUInt32 value);
	EdsUInt32 translate(string property,const char * value);


private:
	void createIsoTable();
	void createSpeedTable();
	void createAvTable();
//	static void createSetCommand(XMLNode* node);
//	static void createGetCommand(XMLNode* node);
//	static void createActionCommand(XMLNode* node);
};

#endif /* DictionaryCanon_h */