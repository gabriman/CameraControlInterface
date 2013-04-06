#include "DictionaryCanon.h"

DictionaryCanon::DictionaryCanon(){
	createIsoTable();
	createSpeedTable();
	createAvTable();
}

void DictionaryCanon::createIsoTable(){
	// Map of value and display name
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x00,"Auto"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x28,"6"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x30,"12"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x38,"25"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x40,"50"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x48,"100"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x4b,"125"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x4d,"160"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x50,"200"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x53,"250"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x55,"320"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x58,"400"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x5b,"500"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x5d,"640"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x60,"800"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x63,"1000"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x65,"1250"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x68,"1600"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x70,"3200"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x78,"6400"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x80,"12800"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x88,"25600"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x90,"51200"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0x98,"102400"));
	_propertyTableISOEds.insert( std::pair<EdsUInt32, const char *>(0xffffffff,"unknown"));

	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("Auto",0x00));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("6",0x28));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("12",0x30));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("25",0x38));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("50",0x40));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("100",0x48));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("125",0x4b));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("160",0x4d));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("200",0x50));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("250",0x53));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("320",0x55));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("400",0x58));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("500",0x5b));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("640",0x5d));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("800",0x60));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("1000",0x63));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("1250",0x65));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("1600",0x68));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("3200",0x70));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("6400",0x78));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("12800",0x80));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("25600",0x88));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("51200",0x90));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("102400",0x98));
	_propertyTableISOString.insert( std::pair<const char *, EdsUInt32>("unknown",0xffffffff));
}

void DictionaryCanon::createSpeedTable(){
	// Map of value and display name
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x0c,"Bulb"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x10,"30"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x13,"25"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x14,"20"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x15,"20"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x18,"15"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x1B,"13"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x1C,"10"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x1D,"10"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x20,"8"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x23,"6"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x24,"6"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x25,"5"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x28,"4"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x2B,"3.2"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x2C,"3"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x2D,"2.5"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x30,"2"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x33,"1.6"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x34,"1.5"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x35,"1.3"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x38,"1"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x3B,"0.8"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x3C,"0.7"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x3D,"0.6"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x40,"0.5"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x43,"0.4"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x44,"0.3"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x45,"0.3"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x48,"1/4"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x4B,"1/5"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x4C,"1/6"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x4D,"1/6"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x50,"1/8"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x53,"1/10"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x54,"1/10"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x55,"1/13"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x58,"1/15"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x5B,"1/20"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x5C,"1/20"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x5D,"1/25"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x60,"1/30"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x63,"1/40"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x64,"1/45"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x65,"1/50"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x68,"1/60"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x6B,"1/80"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x6C,"1/90"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x6D,"1/100"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x70,"1/125"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x73,"1/160"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x74,"1/180"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x75,"1/200"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x78,"1/250"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x7B,"1/320"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x7C,"1/350"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x7D,"1/400"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x80,"1/500"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x83,"1/640"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x84,"1/750"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x85,"1/800"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x88,"1/1000"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x8B,"1/1250"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x8C,"1/1500"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x8D,"1/1600"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x90,"1/2000"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x93,"1/2500"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x94,"1/3000"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x95,"1/3200"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x98,"1/4000"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x9B,"1/5000"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x9C,"1/6000"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0x9D,"1/6400"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0xA0,"1/8000"));
	_propertyTableSpeedEds.insert( std::pair<EdsUInt32, const char *>(0xffffffff,"unknown"));

	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("Bulb",0x0c));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("30",0x10));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("25",0x13));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("20",0x14));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("15",0x18));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("13",0x1B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("10",0x1C));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("8",0x20));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("6",0x23));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("5",0x25));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("4",0x28));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("3.2",0x2B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("3",0x2C));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("2.5",0x2D));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("2",0x30));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1.6",0x33));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1.5",0x34));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1.3",0x35));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1",0x38));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("0.8",0x3B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("0.7",0x3C));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("0.6",0x3D));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("0.5",0x40));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("0.4",0x43));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("0.3",0x44));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/4",0x48));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/5",0x4B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/6",0x4C));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/8",0x50));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/10",0x53));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/13",0x55));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/15",0x58));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/20",0x5B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/25",0x5D));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/30",0x60));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/40",0x63));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/45",0x64));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/50",0x65));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/60",0x68));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/80",0x6B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/90",0x6C));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/100",0x6D));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/125",0x70));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/160",0x73));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/180",0x74));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/200",0x75));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/250",0x78));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/320",0x7B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/350",0x7C));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/400",0x7D));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/500",0x80));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/640",0x83));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/750",0x84));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/800",0x85));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/1000",0x88));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/1250",0x8B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/1500",0x8C));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/1600",0x8D));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/2000",0x90));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/2500",0x93));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/3000",0x94));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/3200",0x95));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/4000",0x98));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/5000",0x9B));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/6000",0x9C));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/6400",0x9D));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("1/8000",0xA0));
	_propertyTableSpeedString.insert( std::pair< const char *, EdsUInt32>("unknown",0xffffffff));
}

void DictionaryCanon::createAvTable(){
	// Map of value and display name
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x00,"00"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x08,"1"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x0B,"1.1"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x0C,"1.2"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x0D,"1.2"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x10,"1.4"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x13,"1.6"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x14,"1.8"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x15,"1.8"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x18,"2"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x1B,"2.2"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x1C,"2.5"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x1D,"2.5"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x20,"2.8"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x23,"3.2"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x24,"3.5"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x25,"3.5"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x28,"4"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x2B,"4.5"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x2C,"4.5"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x2D,"5.0"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x30,"5.6"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x33,"6.3"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x34,"6.7"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x35,"7.1"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x38,"8"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x3B,"9"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x3C,"9.5"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x3D,"10"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x40,"11"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x43,"13"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x44,"13"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x45,"14"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x48,"16"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x4B,"18"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x4C,"19"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x4D,"20"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x50,"22"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x53,"25"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x54,"27"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x55,"29"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x58,"32"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x5B,"36"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x5C,"38"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x5D,"40"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x60,"45"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x63,"51"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x64,"54"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x65,"57"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x68,"64"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x6B,"72"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x6C,"76"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x6D,"80"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0x70,"91"));
	_propertyTableApertureEds.insert( std::pair<EdsUInt32, const char *>(0xffffffff,"unknown"));

	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("00",0x00));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1",0x08));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1.0",0x08));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1.1",0x0B));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1.2",0x0C));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1.2",0x0D));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1.4",0x10));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1.6",0x13));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1.8",0x14));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("1.8",0x15));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("2",0x18));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("2.0",0x18));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("2.2",0x1B));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("2.5",0x1C));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("2.5",0x1D));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("2.8",0x20));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("3.2",0x23));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("3.5",0x24));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("3.5",0x25));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("4",0x28));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("4.0",0x28));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("4.5",0x2B));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("4.5",0x2C));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("5.0",0x2D));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("5.6",0x30));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("6.3",0x33));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("6.7",0x34));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("7.1",0x35));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("8",0x38));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("8.0",0x38));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("9",0x3B));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("9.0",0x3B));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("9.5",0x3C));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("10",0x3D));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("11",0x40));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("13",0x43));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("13",0x44));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("14",0x45));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("16",0x48));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("18",0x4B));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("19",0x4C));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("20",0x4D));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("22",0x50));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("25",0x53));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("27",0x54));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("29",0x55));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("32",0x58));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("36",0x5B));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("38",0x5C));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("40",0x5D));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("45",0x60));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("51",0x63));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("54",0x64));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("57",0x65));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("64",0x68));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("72",0x6B));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("76",0x6C));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("80",0x6D));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("91",0x70));
	_propertyTableApertureString.insert( std::pair<const char *, EdsUInt32>("unknown",0xffffffff));
}

//Fuction for search in map
const char * DictionaryCanon::translate(string prop, EdsUInt32 value)
{
	std::map<EdsUInt32, const char*>::iterator itr;
	std::map<EdsUInt32, const char*> _propertyTable;


	if (!prop.compare("ISO")) {_propertyTable = _propertyTableISOEds;}
	else if (!prop.compare("SPEED")) {_propertyTable = _propertyTableSpeedEds;}
	else if (!prop.compare("APERTURE")) {_propertyTable = _propertyTableApertureEds;}

	itr = _propertyTableISOEds.find(value);

	if (itr!=_propertyTable.end()) return itr->second;
	else return "unknown";
	return NULL;
}

//Fuction for inverse search in map
EdsUInt32 DictionaryCanon::translate(string prop, const char* value)
{
	std::map<const char*, EdsUInt32,cmp_str>::iterator itr;
	std::map<const char*, EdsUInt32,cmp_str> _propertyTable;

	if (!prop.compare("ISO")) {_propertyTable = _propertyTableISOString;}
	else if (!prop.compare("SPEED")) {_propertyTable = _propertyTableSpeedString;}
	else if (!prop.compare("APERTURE")) {_propertyTable = _propertyTableApertureString;}

	itr = _propertyTable.find(value);

	if (itr!=_propertyTable.end()) return itr->second;
	else return EdsUInt32(0xffffffff);
	return NULL;
}