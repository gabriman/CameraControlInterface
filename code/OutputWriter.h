#ifndef OutputWriter_h
#define OutputWriter_h

#include "tinyxml2_lib\tinyxml2.h"
#include "command\ResponseMsg.h"
#include "utils\Utils.h"

using namespace tinyxml2;

// Static class to create command's list from XML
class OutputWriter
{
public:
	static void WriteToFile(ResponseMsg response, tinyxml2::XMLDocument* doc, const char* path, tinyxml2::XMLNode* node);
};

#endif /* OutputWriter_h */