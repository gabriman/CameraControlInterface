//
//Copyright 2013 Gabriel Rodríguez Rodríguez.
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.

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
	 * @brief	Writes an output when camera is closed.
	 *
	 * @param	response	The response.
	 **************************************************************************************************/
	static void WriteCloseOutput(ResponseMsg response);

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