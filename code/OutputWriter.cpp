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


void OutputWriter::WriteCloseOutput(ResponseMsg response){
	std::string path = CommandManager::getPathOut();
	tinyxml2::XMLDocument* doc = CommandManager::getDocOut();

	doc->Clear(); //Clear all text
	XMLNode *root = doc->NewElement("close");
	
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
	delete doc;
}
