#ifndef OutputWriter_h
#define OutputWriter_h

#include "tinyxml2.h"
#include "ResponseMsg.h"
#include "Utils.h"
#include "CommandManager.h"

using namespace tinyxml2;

/**********************************************************************************************//**
 * @brief	Static class to create command's list from XML.
 **************************************************************************************************/
class OutputWriter
{
public:
	/**********************************************************************************************//**
	 * @brief	Writes a response to a XML document.
	 *
	 * @param	response		The response.
	 * @param 	node	If non-null, the node for extract information.
	 **************************************************************************************************/
	static void WriteToDoc(ResponseMsg response, tinyxml2::XMLNode* node);

	/**********************************************************************************************//**
	 * @brief	Writes a response to a XML document. Include value.
	 *
	 * @param	response		The response.
	 * @param 	node			If non-null, the node for extract information.
	 * @param	value			The value.
	 **************************************************************************************************/
	static void WriteToDoc(ResponseMsg response, tinyxml2::XMLNode* node, const char* value);

	/**********************************************************************************************//**
	 * @brief	Writes the command without format.
	 **************************************************************************************************/
	static void WriteCommandNotFormat();

	/**********************************************************************************************//**
	 * @brief	Writes an output when camera is initialized.
	 *
	 * @param	response	The response.
	 **************************************************************************************************/
	static void WriteInitOutput(ResponseMsg response);

	/**********************************************************************************************//**
	 * @brief	Creates and/or clean XML document.
	 *
	 * @param	response	The response.
	 **************************************************************************************************/
	static void CreateOrCleanXMLDoc(ResponseMsg response);

	/**********************************************************************************************//**
	 * @brief	Saves the document to file.
	 * 			
	 **************************************************************************************************/
	static void SaveDocToFile();
};

#endif /* OutputWriter_h */