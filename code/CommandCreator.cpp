#include "CommandCreator.h"


//Static fields declaration
std::string CommandCreator::directoryIn;
std::string CommandCreator::directoryOut;
std::string CommandCreator::pathFileIn;
std::string CommandCreator::pathFileOut;
tinyxml2::XMLDocument* CommandCreator::docIn;
tinyxml2::XMLDocument* CommandCreator::docOut;

CommandCreator::CommandCreator(Camera* camera1, std::string dirIn, std::string dirOut, std::string fIn, std::string fOut):camera(camera1){
	this->directoryIn=dirIn;
	this->directoryOut=dirOut;
	this->pathFileIn=fIn;
	this->pathFileOut=fOut;
}

tinyxml2::XMLDocument* CommandCreator::getDocOut() {
	return docOut;
};

std::string CommandCreator::getPathOut(){
	std::string completePath = directoryOut;
	completePath.append("/");
	completePath = completePath.append(CommandCreator::pathFileOut);
	return completePath;
};

list<Command*> CommandCreator::CreateCommandList(){
	list<Command*> commandsList; //List for append commands
	if (loadXMLFromFiles()<0) {
		cout<<"Error loading files"<<endl;
		return commandsList;
	}
	XMLNode* commands = docIn->FirstChildElement("commands");
	XMLNode* command = commands->FirstChildElement("command");

	//Iterate in "command" tags. command have a "command" tag
	/* We only can have inside <command>:
	<action> for describe a action to do like "shoot"
	<set> for set a parameter
	<get for get a parameter>
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

//XMLDocument
tinyxml2::XMLDocument* CommandCreator::CreateXMLDocument(std::string directory, std::string file, bool out){
	std::string completePath(directory.append("/"));
	completePath = completePath.append(file);
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument;
	if (out){ //If out, create or/and clear
		ofstream myfile;
		myfile.open (completePath.data(),ios::trunc);
		myfile.close();
	}
	doc->LoadFile(completePath.data());
	return doc;
}

int CommandCreator::loadXMLFromFiles(){
	tinyxml2::XMLDocument* docXML_In = CreateXMLDocument(this->directoryIn,this->pathFileIn);
	tinyxml2::XMLDocument* docXML_Out = CreateXMLDocument(this->directoryOut,this->pathFileOut,true);
	cout<<"PATH IN "<<this->directoryIn<<" "<<this->pathFileIn<<endl;
	cout<<"PATH OUT "<<this->directoryOut<<" "<<this->pathFileOut<<endl;
	cout<<"FILE IN "<<pathFileIn.data()<<endl;
	cout<<"FILE OUT "<<pathFileOut.data()<<endl;
	int loadAttempts = 0;
	while (docXML_In->Error()==true && loadAttempts<=MAX_ATTEMPTS_LOAD_FILES){
		loadAttempts++;
		cout<<"Error opening "<<pathFileIn.data()<<" file"<<endl;
		cout<<"charging again "<<endl;
		docXML_In = CreateXMLDocument(this->directoryIn,this->pathFileIn);
		cout<<"charged "<<endl;
	}
	if (loadAttempts>MAX_ATTEMPTS_LOAD_FILES) return -1;
	this->docIn=docXML_In;
	this->docOut=docXML_Out;
	return 0;
};

//We use here a list<Command> instead Command because we assume that several parameters inside <set> are allowed
//TODO: Hacer que funcione para varios set o sino devolver in command normal
Command* CommandCreator::createSetCommand(tinyxml2::XMLNode* node){
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
Command* CommandCreator::createGetCommand(tinyxml2::XMLNode* node){
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

Command* CommandCreator::createGetListCommand(tinyxml2::XMLNode* node){
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

Command* CommandCreator::createActionCommand(tinyxml2::XMLNode* node){
	XMLNode* child;
	child = node->FirstChild();

	const char* parameter = child->Value();
	Command* comando = NULL;

	if (!strcmp(parameter,"take")) comando = new CommandTakePicture(camera,child);
	else return comando = new CommandUnknown(camera,child);

	return comando;
}

Command* CommandCreator::createCloseCommand(){
	Command* comando = NULL;
	comando = new CommandClose(camera);
	return comando;
}

Command* CommandCreator::createUnknownCommand(tinyxml2::XMLNode* node){
	XMLNode* child;
	child = node->FirstChild();
	Command* comando = NULL;
	comando = new CommandUnknown(camera,child);
	return comando;
}