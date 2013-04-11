#ifndef ResponseMsg_h
#define ResponseMsg_h

#define MSG_OK 0
#define MSG_ERROR -1
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
