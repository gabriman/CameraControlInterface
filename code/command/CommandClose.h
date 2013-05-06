#ifndef CommandClose_h
#define CommandClose_h


#include "Camera.h"
#include "Command.h"

/**********************************************************************************************//**
 * @brief	Command close.
 **************************************************************************************************/
class CommandClose : public Command
{
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandClose (Camera* camera);
	virtual int execute();
};

#endif /* CommandClose_h */