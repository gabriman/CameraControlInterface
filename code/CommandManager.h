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

#ifndef CommandCreator_h
#define CommandCreator_h

#include "tinyxml2.h"
#include "Command.h"
#include "Camera.h"
#include <list>
#include "CommandSetIso.h"
#include "CommandSetSpeed.h"
#include "CommandSetAperture.h"
#include "CommandTakePicture.h"
#include "CommandGetIso.h"
#include "CommandGetSpeed.h"
#include "CommandGetAperture.h"
#include "CommandUnknown.h"
#include "CommandGetListIso.h"
#include "CommandGetListAperture.h"
#include "CommandGetListSpeed.h"
#include "CommandSetTargetSave.h"
#include "CommandClose.h"
#include <iostream>
#include <fstream>

#define MAX_ATTEMPTS_LOAD_FILES 20

using namespace tinyxml2;

/**********************************************************************************************//**
 * @brief	Static class to manage command's list from XML
 **************************************************************************************************/
class CommandManager
{
public:
	Camera* camera;
private:
	static std::string directoryIn;
	static std::string directoryOut;
	static std::string pathFileIn;
	static std::string pathFileOut;
	static tinyxml2::XMLDocument* docIn;
	static tinyxml2::XMLDocument* docOut;

public:
	/**********************************************************************************************//**
	 * @brief	Default Constructor.
	 **************************************************************************************************/
	CommandManager(){};


	/**********************************************************************************************//**
	 * @brief	Constructor.
	 *
	 * @param [in,out]	camera1	If non-null, the first camera.
	 * @param	dirIn		   	The dir in.
	 * @param	dirOut		   	The dir out.
	 * @param	fIn			   	The in.
	 * @param	fOut		   	The out.
	 **************************************************************************************************/
	CommandManager(Camera* camera1, std::string dirIn, std::string dirOut, std::string fIn, std::string fOut);

	/**********************************************************************************************//**
	 * @brief	Creates command list.
	 *
	 * @return	null if it fails, else the new command list.
	 **************************************************************************************************/
	list<Command*> CreateCommandList();

	/**********************************************************************************************//**
	 * @brief	Executes the command list operation.
	 *
	 * @param [in,out]	commandsList	If non-null, list of commands.
	 *
	 * @return	.
	 **************************************************************************************************/
	int executeCommandList(list<Command*> commandsList);

	/**********************************************************************************************//**
	 * @brief	Gets document out.
	 *
	 * @return	null if it fails, else the document out.
	 **************************************************************************************************/
	static tinyxml2::XMLDocument* getDocOut();

	/**********************************************************************************************//**
	 * @brief	Gets path out.
	 *
	 * @return	The path out.
	 **************************************************************************************************/
	static std::string getPathOut();
private:
	/**********************************************************************************************//**
	 * @brief	Loads XML from files.
	 *
	 * @return	The XML from files.
	 **************************************************************************************************/
	int loadXMLFromFiles();

	/**********************************************************************************************//**
	 * @brief	Creates set command.
	 *
	 * @param [in,out]	node	If non-null, the node.
	 *
	 * @return	null if it fails, else the new set command.
	 **************************************************************************************************/
	Command* createSetCommand(XMLNode* node);

	/**********************************************************************************************//**
	 * @brief	Creates get command.
	 *
	 * @param [in,out]	node	If non-null, the node.
	 *
	 * @return	null if it fails, else the new get command.
	 **************************************************************************************************/
	Command* createGetCommand(XMLNode* node);

	/**********************************************************************************************//**
	 * @brief	Creates get list command.
	 *
	 * @param [in,out]	node	If non-null, the node.
	 *
	 * @return	null if it fails, else the new get list command.
	 **************************************************************************************************/
	Command* createGetListCommand(XMLNode* node);

	/**********************************************************************************************//**
	 * @brief	Creates action command.
	 *
	 * @param [in,out]	node	If non-null, the node.
	 *
	 * @return	null if it fails, else the new action command.
	 **************************************************************************************************/
	Command* createActionCommand(XMLNode* node);

	/**********************************************************************************************//**
	 * @brief	Creates unknown command.
	 *
	 * @param [in,out]	node	If non-null, the node.
	 *
	 * @return	null if it fails, else the new unknown command.
	 **************************************************************************************************/
	Command* createUnknownCommand(XMLNode* node);

	/**********************************************************************************************//**
	 * @brief	Creates close command.
	 *
	 * @return	null if it fails, else the new close command.
	 **************************************************************************************************/
	Command* createCloseCommand();

	/**********************************************************************************************//**
	 * @brief	Creates XML document and load a XML document.
	 * 			If is a input file, load it. If is output file, create it and insert <commands> section empty
	 *
	 * @param	directory	Pathname of the directory.
	 * @param	file	 	Pathname of the file.
	 * @param	out		 	true if is output file.
	 *
	 * @return	null if it fails, else the new XML document.
	 **************************************************************************************************/
	tinyxml2::XMLDocument* CreateXMLDocument(std::string directory, std::string file, bool out = false);
};

#endif /* CommandCreator_h */