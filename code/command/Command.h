#ifndef Command_h
#define Command_h


#include "Camera.h"
#include "tinyxml2.h"
class Command
{
protected:
	Camera* camera; //Camera command target
	tinyxml2::XMLNode* nodeOut; //Node for write output
public: 
	/**********************************************************************************************//**
	 * @brief	Constructor.
	 *
	 * @param [in,out]	c	If non-null, the Camera* to process.
	 **************************************************************************************************/
	Command (Camera* c);

	/**********************************************************************************************//**
	 * @brief	Constructor with node.
	 *
	 * @param [in,out]	c   	The Camera* to process.
	 * @param [in,out]	node	The node.
	 **************************************************************************************************/
	Command (Camera* c, tinyxml2::XMLNode* node);
	
	/**********************************************************************************************//**
	 * @brief	Execute the command.
	 *
	 * @return	integer for notify error. If the code is negative, an error has occurred.
	 **************************************************************************************************/
	virtual int execute(){return -1;};
};

#endif /* Command_h */