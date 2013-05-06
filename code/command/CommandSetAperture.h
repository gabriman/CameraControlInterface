#ifndef CommandSetAperture_h
#define CommandSetAperture_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command to set aperture.
 **************************************************************************************************/
class CommandSetAperture : public Command
{
private:
	char newValue[30];
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandSetAperture (Camera* camera1, const char* value, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandSetAperture_h */