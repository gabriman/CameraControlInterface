#include "CommandCreator.h"



CommandCreator::CommandCreator(Camera* camera1):camera(camera1){};

list<Command*> CommandCreator::CreateCommandList(tinyxml2::XMLDocument* doc){
	
	list<Command*> commandsList; //List for append commands
	XMLNode* commands = doc->FirstChildElement( "commands");
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
			createGetCommand(nodeCommand);
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

void CommandCreator::createGetCommand(tinyxml2::XMLNode* node){

	cout<<"get detected"<<endl;
}

Command* CommandCreator::createActionCommand(tinyxml2::XMLNode* node){
	//Command c;
	cout<<"action detected"<<endl;
	Command* comando = NULL;

	const char* value = (const char*)node->FirstChild()->Value();

	if (!strcmp(value,"take")) comando = new CommandTakePicture(camera);

	return comando;

}