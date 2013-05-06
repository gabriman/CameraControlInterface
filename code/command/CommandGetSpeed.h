#ifndef CommandGetSpeed_h
#define CommandGetSpeed_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command get list speed.
 **************************************************************************************************/
class CommandGetSpeed : public Command
{
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandGetSpeed (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandGetSpeed_h */