#ifndef CommandSetSpeed_h
#define CommandSetSpeed_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command set speed.
 **************************************************************************************************/
class CommandSetSpeed : public Command
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
	CommandSetSpeed (Camera* camera1, const char* value, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandSetSpeed_h */