#ifndef CommandGetIso_h
#define CommandGetIso_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command get iso.
 **************************************************************************************************/
class CommandGetIso : public Command
{
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandGetIso (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandGetIso_h */