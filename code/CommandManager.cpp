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

//#define _CRTDBG_MAP_ALLOC //Debug memory leaks
#include "CommandManager.h"


//Static fields declaration
std::string CommandManager::directoryIn;
std::string CommandManager::directoryOut;
std::string CommandManager::pathFileIn;
std::string CommandManager::pathFileOut;
tinyxml2::XMLDocument* CommandManager::docIn;
tinyxml2::XMLDocument* CommandManager::docOut;

CommandManager::CommandManager(Camera* camera1, std::string dirIn, std::string dirOut, std::string fIn, std::string fOut):camera(camera1){
	this->directoryIn=dirIn;
	this->directoryOut=dirOut;
	this->pathFileIn=fIn;
	this->pathFileOut=fOut;
	loadXMLFromFiles();
}

tinyxml2::XMLDocument* CommandManager::getDocOut() {
	return docOut;
};

std::string CommandManager::getPathOut(){
	std::string completePath = directoryOut;
	completePath.append("/");
	completePath = completePath.append(CommandManager::pathFileOut);
	return completePath;
};

list<Command*> CommandManager::CreateCommandList(){
	list<Command*> commandsList; //List for append commands
	if (loadXMLFromFiles()<0) {
		cout<<"Error loading files"<<endl;
		return commandsList;
	}

	XMLNode* commands = docIn->FirstChildElement("commands");
	if (commands==NULL) return commandsList;

	XMLNode* command = commands->FirstChildElement("command");
	if (command==NULL) return commandsList;

	//Iterate in "command" tags. command have a "command" tag
	/* We only can have inside <command>:
	<action> for describe a action to do like "shoot"
	<set> for set parameter's value
	<get> for get parameter's value
	<getlist> for get a list of avaliable values for a parameter 
	*/
	do{ 
		XMLNode* nodeCommand = command->FirstChild();
		string value = nodeCommand->Value();
		cout<<"VALUE "<<value.c_str()<<endl;
		if (!value.compare("action"))
			commandsList.push_back(createActionCommand(nodeCommand));
		else if (!value.compare("set"))
			commandsList.push_back(createSetCommand(nodeCommand));
		else if (!value.compare("get"))
			commandsList.push_back(createGetCommand(nodeCommand));
		else if (!value.compare("getlist"))
			commandsList.push_back(createGetListCommand(nodeCommand));
		else if (!value.compare("close")) 
			commandsList.push_back(createCloseCommand());
		else commandsList.push_back(createUnknownCommand(nodeCommand));
	}while ((command=command->NextSibling())!=NULL);

	return commandsList;
}


tinyxml2::XMLDocument* CommandManager::CreateXMLDocument(std::string directory, std::string file, bool out){
	std::string completePath(directory.append("\\"));
	completePath = completePath.append(file);
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument;
	if (out){ //If out, create or/and clear
		ofstream myfile;
		myfile.open (completePath.data(),ios::trunc);
		myfile.close();
		XMLElement* valueElement = doc->NewElement("commands"); 	//Insert commads section
		doc->InsertEndChild(valueElement);
	}
	else
		doc->LoadFile(completePath.data());
	return doc;
}

int CommandManager::loadXMLFromFiles(){
	tinyxml2::XMLDocument* docXML_In = CreateXMLDocument(this->directoryIn,this->pathFileIn);
	tinyxml2::XMLDocument* docXML_Out = CreateXMLDocument(this->directoryOut,this->pathFileOut,true);
	int loadAttempts = 0;
	while (docXML_In->Error()==true && loadAttempts<=MAX_ATTEMPTS_LOAD_FILES){
		loadAttempts++;
		cout<<"Error opening "<<pathFileIn.data()<<" file"<<endl;
		cout<<"charging again "<<endl;
		docXML_In = CreateXMLDocument(this->directoryIn,this->pathFileIn);
		cout<<"charged "<<endl;
	}
	if (loadAttempts>MAX_ATTEMPTS_LOAD_FILES) {	cout<<"max numero intentos"<<endl;return -1;}
	cout<<"archivos cargados"<<endl;
	this->docIn=docXML_In;
	this->docOut=docXML_Out;
	return 0;
}

//We use here a list<Command> instead Command because we assume that several parameters inside <set> are allowed
//TODO: Hacer que funcione para varios set o sino devolver in command normal
Command* CommandManager::createSetCommand(tinyxml2::XMLNode* node){
	list<Command> command;
	XMLNode* child;
	child = node->FirstChild();

	const char* parameter = child->Value();
	const char* value = (const char*)child->FirstChild()->Value();

	Command* comando = NULL;

	if		(!strcmp(parameter,"ISO")) comando = new CommandSetIso(camera,value,child);
	else if ( !strcmp(parameter,"SPEED")) comando = new CommandSetSpeed(camera,value,child);
	else if ( !strcmp(parameter,"APERTURE")) comando = new CommandSetAperture(camera,value,child);
	else return comando = new CommandUnknown(camera,child);

	return comando;
}

//We are in the node of GET
Command* CommandManager::createGetCommand(tinyxml2::XMLNode* node){
	list<Command> command;
	XMLNode* child;
	child = node->FirstChild();

	const char* parameter = child->Value();
	Command* comando = NULL;

	if	(!strcmp(parameter,"ISO")) comando = new CommandGetIso(camera,child);
	else if ( !strcmp(parameter,"SPEED")) comando = new CommandGetSpeed(camera,child);
	else if ( !strcmp(parameter,"APERTURE")) comando = new CommandGetAperture(camera,child);
	else return comando = new CommandUnknown(camera,child);

	return comando;
}

Command* CommandManager::createGetListCommand(tinyxml2::XMLNode* node){
	list<Command> command;
	XMLNode* child;
	child = node->FirstChild();

	const char* parameter = child->Value();
	Command* comando = NULL;

	if	(!strcmp(parameter,"ISO")) comando = new CommandGetListIso(camera,child);
	else if ( !strcmp(parameter,"SPEED")) comando = new CommandGetListSpeed(camera,child);
	else if ( !strcmp(parameter,"APERTURE")) comando = new CommandGetListAperture(camera,child);
	else return comando = new CommandUnknown(camera,child);

	return comando;
}

Command* CommandManager::createActionCommand(tinyxml2::XMLNode* node){
	XMLNode* child;
	child = node->FirstChild();

	const char* parameter = child->Value();
	Command* comando = NULL;

	if (!strcmp(parameter,"take")) comando = new CommandTakePicture(camera,child);
	else if (!strcmp(parameter,"targetSave")){
		XMLNode* tarjetNode = child->FirstChildElement("target");
		XMLNode* pathNode = child->FirstChildElement("path");
		string target = tarjetNode->FirstChild()->Value();
		string path;
		if (pathNode==NULL) path = camera->getPathSavePhotos();
		else if (pathNode->FirstChild()!=NULL)
				path = pathNode->FirstChild()->Value();
			else
				path="";
		comando = new CommandSetTargetSave(camera,target,path,child);
	}
	else return comando = new CommandUnknown(camera,child);

	return comando;
}

Command* CommandManager::createCloseCommand(){
	Command* comando = NULL;
	comando = new CommandClose(camera);
	return comando;
}

Command* CommandManager::createUnknownCommand(tinyxml2::XMLNode* node){
	XMLNode* child;
	child = node->FirstChild();
	Command* comando = NULL;
	comando = new CommandUnknown(camera,child);
	return comando;
}



int CommandManager::executeCommandList(list<Command*> commandsList){
	for (list<Command*>::iterator i = commandsList.begin(); i != commandsList.end(); i++){
		if ((*i)->execute()<0){
			delete (*i);
			break;   //Execute and  stop to execute commands if return a error
		}
		else delete (*i);
	}
	OutputWriter::SaveDocToFile();
	return 0;
}