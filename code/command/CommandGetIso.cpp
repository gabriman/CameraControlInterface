#include "CommandGetIso.h"

CommandGetIso::CommandGetIso(Camera* camera1):Command(camera1){}

CommandGetIso::CommandGetIso(Camera* camera1, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node):Command(camera1,doc,node){}

using namespace tinyxml2;

void CommandGetIso::execute(){
	cout<<"Ejecuting getISO"<<endl;
	char* value;
	value="200"; //Valor de ejemplo mientras no este implementado
	cout<<"Iso obtenido"<<endl;

	ResponseMsg response(MSG_OK,value);
	OutputWriter::WriteToFile(response,this->nodeOut);
}