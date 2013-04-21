#ifndef ResponseMsg_h
#define ResponseMsg_h
#include <string>

using namespace std;
class ResponseMsg
{
private:
	int code;	//OK, ERROR,...
	char* message;
public:
	ResponseMsg(int code, char* message);
	ResponseMsg(int code, string message);
	int getCode();
	const char* getMessage();
};


#endif /* ResponseMsg_h */
