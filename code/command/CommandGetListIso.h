#ifndef CommandGetListIso_h
#define CommandGetListIso_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command get list iso.
 **************************************************************************************************/
class CommandGetListIso : public Command
{
public: 
	CommandGetListIso (Camera* camera1);
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandGetListIso (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandGetListIso_h */