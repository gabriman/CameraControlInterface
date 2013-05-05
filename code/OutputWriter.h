#ifndef OutputWriter_h
#define OutputWriter_h

#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "Utils.h"
#include "CommandManager.h"

using namespace tinyxml2;

// Static class to create command's list from XML
class OutputWriter
{
public:
	static void WriteToDoc(ResponseMsg response, tinyxml2::XMLNode* node);
	static void WriteToDoc(ResponseMsg response, tinyxml2::XMLNode* node, const char* value);
	static void WriteCommandNotFormat();
	static void WriteInitOutput(ResponseMsg response);
	static void CreateOrCleanXMLDoc(ResponseMsg response);
	static void SaveDocToFile();
};

#endif /* OutputWriter_h */