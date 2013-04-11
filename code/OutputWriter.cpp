#include "OutputWriter.h"

void OutputWriter::WriteToFile(ResponseMsg response,tinyxml2::XMLDocument* doc, const char* path, XMLNode* node){
	//Searching root
	XMLNode *root = node;
	while(strcmp(root->Value(),"command")!=0)
	{root=root->Parent();}

	XMLText* textCode = doc->NewText((Utils::convertInt(response.getCode()).c_str()));
	XMLText* textMessage = doc->NewText(response.getMessage());

	XMLElement* codeElement = doc->NewElement("code");
	XMLElement* messageElement = doc->NewElement("message");

	node->InsertEndChild(codeElement);
	node->InsertEndChild(messageElement);

	codeElement->InsertEndChild(textCode);
	messageElement->InsertEndChild(textMessage);

	doc->InsertEndChild(root);
	doc->SaveFile(path);
}


