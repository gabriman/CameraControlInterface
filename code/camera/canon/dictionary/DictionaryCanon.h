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