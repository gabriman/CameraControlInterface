#ifndef CommandGetAperture_h
#define CommandGetAperture_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command get aperture.
 **************************************************************************************************/
class CommandGetAperture : public Command
{
public: 
	CommandGetAperture (Camera* camera1);

	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandGetAperture (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandGetAperture_h */