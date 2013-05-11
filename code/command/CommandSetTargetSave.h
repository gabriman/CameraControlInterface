#ifndef CommandSetTargetSave_h
#define CommandSetTargetSave_h


#include "Camera.h"
#include "Command.h"
#include "OutputWriter.h"

/**********************************************************************************************//**
 * @brief	Command to set the target where photo are saved.
 **************************************************************************************************/
class CommandSetTargetSave : public Command
{
private:
	string target;
	string path;
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor
	 *
	 * @param [in]	camera1	The camera.
	 * @param [in]	node   	The node.
	 **************************************************************************************************/
	CommandSetTargetSave (Camera* camera1, std::string target, std::string path, tinyxml2::XMLNode* node);
	virtual int execute();
};

#endif /* CommandSetAperture_h */