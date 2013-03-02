#ifndef DictionaryCanon_h
#define DictionaryCanon_h

#include <map>
#include "EDSDKTypes.h"

using namespace std;

// Static class to create command's list from XML
class DictionaryCanon
{
private:
	std::map<EdsUInt32, const char *> _propertyTableISOeds;
	std::map<const char *, EdsUInt32> _propertyTableISOstring;

	std::map<EdsUInt32, const char *> _propertyTableSpeed;
	std::map<EdsUInt32, const char *> _propertyTableAv;

public:
	DictionaryCanon();
	const char * translateISO(EdsUInt32 value);
	EdsUInt32 translateISO(const char * value);


private:
	void createIsoTable();
//	static void createSetCommand(XMLNode* node);
//	static void createGetCommand(XMLNode* node);
//	static void createActionCommand(XMLNode* node);
};

#endif /* DictionaryCanon_h */