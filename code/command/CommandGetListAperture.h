#ifndef CommandGetListAperture_h
#define CommandGetListAperture_h


#include "Camera.h"
#include "Command.h"
#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command get list aperture.
 **************************************************************************************************/
class CommandGetListAperture : public Command
{
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandGetListAperture (Camera* camera1, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandGetListAperture_h */