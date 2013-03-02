#include "DictionaryCanon.h"

DictionaryCanon::DictionaryCanon(){

	createIsoTable();

}


void DictionaryCanon::createIsoTable(){

	// Map of value and display name
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x00,"Auto"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x28,"6"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x30,"12"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x38,"25"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x40,"50"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x48,"100"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x4b,"125"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x4d,"160"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x50,"200"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x53,"250"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x55,"320"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x58,"400"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x5b,"500"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x5d,"640"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x60,"800"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x63,"1000"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x65,"1250"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x68,"1600"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x70,"3200"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x78,"6400"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x80,"12800"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x88,"25600"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x90,"51200"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0x98,"102400"));
	_propertyTableISOeds.insert( std::pair<EdsUInt32, const char *>(0xffffffff,"unknown"));

	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("Auto",0x00));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("6",0x28));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("12",0x30));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("25",0x38));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("50",0x40));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("100",0x48));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("125",0x4b));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("160",0x4d));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("200",0x50));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("250",0x53));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("320",0x55));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("400",0x58));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("500",0x5b));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("640",0x5d));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("800",0x60));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("1000",0x63));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("1250",0x65));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("1600",0x68));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("3200",0x70));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("6400",0x78));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("12800",0x80));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("25600",0x88));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("51200",0x90));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("102400",0x98));
	_propertyTableISOeds.insert( std::pair<const char *, EdsUInt32>("unknown",0xffffffff));

}


//Fuction for search in map
const char * DictionaryCanon::translateISO( EdsUInt32 value)
{
	std::map<EdsUInt32, const char*>::iterator itr = _propertyTableISOeds.find(value);
	return itr->second;
}

//Fuction for inverse search in map
EdsUInt32 DictionaryCanon::translateISO( const char* value)
{
	std::map<const char*,EdsUInt32>::iterator itr = _propertyTableISOstring.find(value);
	return itr->second;
}