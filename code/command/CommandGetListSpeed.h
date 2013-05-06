#ifndef CommandGetListSpeed_h
#define CommandGetListSpeed_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command get list speed.
 **************************************************************************************************/
class CommandGetListSpeed : public Command
{
public: 
	CommandGetListSpeed (Camera* camera1);
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandGetListSpeed (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandGetListSpeed_h */