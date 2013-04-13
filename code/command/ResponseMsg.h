#ifndef ResponseMsg_h
#define ResponseMsg_h

using namespace std;

class ResponseMsg
{
private:
	int code;	//OK, ERROR,...
	const char* message;
public:
	ResponseMsg(int code, const char* message);
	int getCode();
	const char* getMessage();
};


#endif /* ResponseMsg_h */
