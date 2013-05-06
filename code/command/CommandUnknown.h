#ifndef CommandUnknown_h
#define CommandUnknown_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Create a command to use when the command format is not recognized
 **************************************************************************************************/
class CommandUnknown : public Command
{
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandUnknown (Camera* camera1, tinyxml2::XMLNode* node);

	virtual int execute();
};

#endif /* CommandUnknown_h */