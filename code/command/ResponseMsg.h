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
