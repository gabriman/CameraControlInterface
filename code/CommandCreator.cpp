#include "CommandCreator.h"





list<Command> CommandCreator::CreateCommandList(Camera* camera,tinyxml2::XMLDocument* doc){


	list<Command> commandsList; //List for append commands
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
			createActionCommand(nodeCommand);
		}
		else if (!value.compare("set")){
			createSetCommand(nodeCommand);
		}
		else if (!value.compare("get")){
			createGetCommand(nodeCommand);
		}

	}while ((command=command->NextSibling())!=NULL); 


	/*if (textNode!=NULL){
	std::string title = textNode->Value();

	if (title.compare("command"))
	{


	}

	}*/
	//printf( "Parameteres.*: %s %s\n", textNode->Value(), textNode->FirstChild()->ToText()->Value() );


	return commandsList;


}

//We use here a list<Command> instead Command because we assume that several parameters inside <set> are allowed
void CommandCreator::createSetCommand(tinyxml2::XMLNode* node){
	list<Command> commandsList;
	cout<<"set detected"<<endl;
}

void CommandCreator::createGetCommand(tinyxml2::XMLNode* node){

	cout<<"get detected"<<endl;
}

void CommandCreator::createActionCommand(tinyxml2::XMLNode* node){
	//Command c;
	cout<<"action detected"<<endl;

}