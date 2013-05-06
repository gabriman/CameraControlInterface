#ifndef CommandSetIso_h
#define CommandSetIso_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command to set aperture.
 **************************************************************************************************/
class CommandSetIso : public Command
{
private:
	char newValue[30];
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandSetIso (Camera* camera1, const char* value, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandSetIso_h */