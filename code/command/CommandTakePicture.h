#ifndef CommandTakePicture_h
#define CommandTakePicture_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command take picture.
 **************************************************************************************************/
class CommandTakePicture : public Command
{
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandTakePicture (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandTakePicture_h */