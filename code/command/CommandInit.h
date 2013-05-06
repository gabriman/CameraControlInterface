#ifndef CommandInit_h
#define CommandInit_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command initialise camera.
 **************************************************************************************************/
class CommandInit : public Command
{
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandInit (Camera* camera);
	virtual int execute();
};

#endif /* CommandInit_h */