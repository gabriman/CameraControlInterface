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

#ifndef ResponseMsg_h
#define ResponseMsg_h
#include <string>

using namespace std;

/**********************************************************************************************//**
 * @brief	Class to store the response message commands. 
 * @details		Stores the response code, the possible error messages and the return value (if any).
 **************************************************************************************************/
class ResponseMsg
{
private:
	int code;
	char* message;
public:
	/**********************************************************************************************//**
	 * @brief	Constructor with char* message..
	 *
	 * @param	code		   	The code.
	 * @param [in]	message		The message.
	 **************************************************************************************************/
	ResponseMsg(int code, char* message);

	/**********************************************************************************************//**
	 * @brief	Constructor with string message.
	 *
	 * @param	code   	The code.
	 * @param	message	The message.
	 **************************************************************************************************/
	ResponseMsg(int code, string message);

	/**********************************************************************************************//**
	 * @brief	Gets the code.
	 *
	 * @return	The code.
	 **************************************************************************************************/
	int getCode();

	/**********************************************************************************************//**
	 * @brief	Gets the message.
	 *
	 * @return	null if it fails, else the message.
	 **************************************************************************************************/
	const char* getMessage();
};


#endif /* ResponseMsg_h */
