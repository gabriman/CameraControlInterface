#include "OutputWriter.h"




void OutputWriter::WriteToDoc(ResponseMsg response, XMLNode* node){
	std::string path = CommandManager::getPathOut();
	tinyxml2::XMLDocument* doc = CommandManager::getDocOut();

	//Searching root
	XMLNode *root = node;
	while(strcmp(root->Value(),"command")!=0)
	{root=root->Parent();}

	XMLText* textCode = doc->NewText((Utils::convertInt(response.getCode()).c_str()));
	XMLText* textMessage = doc->NewText(response.getMessage());

	XMLElement* codeElement = doc->NewElement("code");
	node->InsertEndChild(codeElement);
	XMLElement* messageElement = doc->NewElement("message");
	node->InsertEndChild(messageElement);
	codeElement->InsertEndChild(textCode);
	messageElement->InsertEndChild(textMessage);


	XMLElement* commandsElement = doc->FirstChildElement("commands");
	commandsElement->InsertEndChild(root);
}



void OutputWriter::WriteToDoc(ResponseMsg response, XMLNode* node, const char* value){
	std::string path = CommandManager::getPathOut();
	tinyxml2::XMLDocument* doc = CommandManager::getDocOut();

	//Searching root
	XMLNode *root = node;
	while(strcmp(root->Value(),"command")!=0)
	{root=root->Parent();}

	XMLText* textCode = doc->NewText((Utils::convertInt(response.getCode()).c_str()));
	XMLText* textMessage = doc->NewText(response.getMessage());
	XMLText* valueMessage = doc->NewText(value);

	node->DeleteChildren();
	XMLElement* codeElement = doc->NewElement("code");
	node->InsertEndChild(codeElement);
	XMLElement* messageElement = doc->NewElement("message");
	node->InsertEndChild(messageElement);
	XMLElement* valueElement = doc->NewElement("value"); 	//Insert the value
	node->InsertEndChild(valueElement);

	codeElement->InsertEndChild(textCode);
	messageElement->InsertEndChild(textMessage);
	valueElement->InsertEndChild(valueMessage);

	XMLElement* commandsElement = doc->FirstChildElement("commands");
	commandsElement->InsertEndChild(root);
}


void OutputWriter::WriteCommandNotFormat(){
	std::string path = CommandManager::getPathOut();
	tinyxml2::XMLDocument* doc = CommandManager::getDocOut();

	XMLNode *root = doc->NewElement("command");

	XMLText* textCode = doc->NewText((Utils::convertInt(CAMERROR_VALUE_UNKNOWN)).c_str());

	XMLElement* codeElement = doc->NewElement("code");
	root->InsertEndChild(codeElement);

	codeElement->InsertEndChild(textCode);

	XMLElement* commandsElement = doc->FirstChildElement("commands");
	commandsElement->InsertEndChild(root);
}




void OutputWriter::WriteInitOutput(ResponseMsg response){
	std::string path = CommandManager::getPathOut();
	tinyxml2::XMLDocument* doc = CommandManager::getDocOut();

	doc->Clear(); //Clear all text
	XMLNode *root = doc->NewElement("init");
	
	XMLText* textCode = doc->NewText((Utils::convertInt(response.getCode()).c_str()));
	XMLText* textMessage = doc->NewText(response.getMessage());

	XMLElement* codeElement = doc->NewElement("code");
	root->InsertEndChild(codeElement);
	XMLElement* messageElement = doc->NewElement("message");
	root->InsertEndChild(messageElement);

	codeElement->InsertEndChild(textCode);
	messageElement->InsertEndChild(textMessage);

	doc->InsertEndChild(root);
	doc->SaveFile(path.c_str());
}




void OutputWriter::CreateOrCleanXMLDoc(ResponseMsg response){
	//std::string path = CommandManager::getPathOut();
	//tinyxml2::XMLDocument* doc = CommandManager::getDocOut();

	//XMLNode *root = doc->NewElement("init");

	//XMLText* textCode = doc->NewText((Utils::convertInt(response.getCode()).c_str()));
	//XMLText* textMessage = doc->NewText(response.getMessage());
	//XMLText* valueMessage = doc->NewText(value);

	//node->DeleteChildren();
	//XMLElement* codeElement = doc->NewElement("code");
	//node->InsertEndChild(codeElement);
	//XMLElement* messageElement = doc->NewElement("message");
	//node->InsertEndChild(messageElement);

	//XMLElement* codeElement = doc->NewElement("code");
	//root->InsertEndChild(codeElement);

	//codeElement->InsertEndChild(textCode);

	//doc->InsertEndChild(root);
	//doc->SaveFile(path.c_str());
}




void OutputWriter::SaveDocToFile(){
	std::string path = CommandManager::getPathOut();
	tinyxml2::XMLDocument* doc = CommandManager::getDocOut();
	doc->SaveFile(path.c_str());
}
