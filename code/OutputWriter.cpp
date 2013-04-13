#include "OutputWriter.h"

/**
 * @brief Output writer explanation
 * 
 * EXAMPLE
 * <command>
 *	<get>
 *		<APERTURE>
 *          <code>0</code>
 *          <message>7.1</message>
 *      </APERTURE>
 *	</get>
 * </command>
*/
void OutputWriter::WriteToFile(ResponseMsg response, XMLNode* node){
	std::string path = CommandCreator::getPathOut();
	tinyxml2::XMLDocument* doc = CommandCreator::getDocOut();

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

	doc->InsertEndChild(root);
	doc->SaveFile(path.c_str());
}

/*<command>
    <set>
        <ISO>220<code>-4</code>
            <message>Value not suported</message>
        </ISO>
    </set>
</command>*/
void OutputWriter::WriteToFile(ResponseMsg response, XMLNode* node, const char* value){
	std::string path = CommandCreator::getPathOut();
	tinyxml2::XMLDocument* doc = CommandCreator::getDocOut();

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

	doc->InsertEndChild(root);
	doc->SaveFile(path.c_str());
}

void OutputWriter::WriteCommandNotFormat(){
	std::string path = CommandCreator::getPathOut();
	tinyxml2::XMLDocument* doc = CommandCreator::getDocOut();

	//Searching root
	XMLNode *root = doc->NewElement("command");

	XMLText* textCode = doc->NewText((Utils::convertInt(CAMERROR_VALUE_UNKNOWN)).c_str());
	
	XMLElement* codeElement = doc->NewElement("code");
	root->InsertEndChild(codeElement);
	
	codeElement->InsertEndChild(textCode);

	doc->InsertEndChild(root);
	doc->SaveFile(path.c_str());
}