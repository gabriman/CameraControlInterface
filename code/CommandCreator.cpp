#include "CommandCreator.h"


//Static fields declaration
std::string CommandCreator::directoryIn;
std::string CommandCreator::directoryOut;
std::string CommandCreator::fileIn;
std::string CommandCreator::fileOut;
tinyxml2::XMLDocument* CommandCreator::docIn;
tinyxml2::XMLDocument* CommandCreator::docOut;

CommandCreator::CommandCreator(Camera* camera1, std::string dirIn, std::string dirOut, std::string fIn, std::string fOut):camera(camera1){
	this->directoryIn=dirIn;
	this->directoryOut=dirOut;
	this->fileIn=fIn;
	this->fileOut=fOut;
}

tinyxml2::XMLDocument* CommandCreator::getDocOut() {
	return docOut;
};

std::string CommandCreator::getPathOut(){
	std::string completePath = CommandCreator::directoryOut.append("/");
	completePath = completePath.append(CommandCreator::fileOut);
	return completePath;
};

//XMLDocument
tinyxml2::XMLDocument* CommandCreator::CreateXMLDocument(std::string directory, std::string file, bool out){
	std::string completePath = directory.append("/");
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

void CommandCreator::loadXMLFromFiles(){
	tinyxml2::XMLDocument* docXML_In = CreateXMLDocument(this->directoryIn,this->fileIn);
	tinyxml2::XMLDocument* docXML_Out = CreateXMLDocument(this->directoryOut,this->fileOut,true);
	if (docXML_In->Error()==true){
		cout<<"Error opening "<<fileIn.data()<<" file"<<endl;
		return;
	}
	this->docIn=docXML_In;
	this->docOut=docXML_Out;
	
};

list<Command*> CommandCreator::CreateCommandList(){
	loadXMLFromFiles();

	list<Command*> commandsList; //List for append commands
	XMLNode* commands = docIn->FirstChildElement( "commands");
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
		if (!value.compare("action")){
			commandsList.push_back(createActionCommand(nodeCommand));
		}
		else if (!value.compare("set")){
			commandsList.push_back(createSetCommand(nodeCommand));
		}
		else if (!value.compare("get")){
			commandsList.push_back(createGetCommand(nodeCommand));
		}
	}while ((command=command->NextSibling())!=NULL);

	return commandsList;
}

//We use here a list<Command> instead Command because we assume that several parameters inside <set> are allowed
//TODO: Hacer que funcione para varios set o sino devolver in command normal
Command* CommandCreator::createSetCommand(tinyxml2::XMLNode* node){
	list<Command> command;
	XMLNode* child;
	child = node->FirstChild();

	const char* parameter = child->Value();
	const char* value = (const char*)child->FirstChild()->Value();

	Command* comando = NULL;

	if		(!strcmp(parameter,"ISO")) comando = new CommandSetIso(camera,value);
	else if ( !strcmp(parameter,"SPEED")) comando = new CommandSetSpeed(camera,value);
	else if ( !strcmp(parameter,"APERTURE")) comando = new CommandSetAperture(camera,value);

	//	comando->execute();
	return comando;
}

//We are in the node of GET
Command* CommandCreator::createGetCommand(tinyxml2::XMLNode* node){
	list<Command> command;
	XMLNode* child;
	child = node->FirstChild();

	const char* parameter = child->Value();
	Command* comando = NULL;

	if	(!strcmp(parameter,"ISO")) comando = new CommandGetIso(camera,docOut,child);
	else if ( !strcmp(parameter,"SPEED")) comando = new CommandGetSpeed(camera,docOut,child);
	else if ( !strcmp(parameter,"APERTURE")) comando = new CommandGetAperture(camera,docOut,child);

	return comando;
}

Command* CommandCreator::createActionCommand(tinyxml2::XMLNode* node){
	//Command c;
	cout<<"action detected"<<endl;
	Command* comando = NULL;

	const char* value = (const char*)node->FirstChild()->Value();

	if (!strcmp(value,"take")) comando = new CommandTakePicture(camera);

	return comando;

}