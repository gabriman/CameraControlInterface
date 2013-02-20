#include "Utils.h"

using namespace std;

//This will be in a UTILS file
TCHAR* Utils::stringToTCHAR(std::string str){
	TCHAR *param=new TCHAR[str.size()+1];
	param[str.size()]=0;
	//As much as we'd love to, we can't use memcpy() because
	//sizeof(TCHAR)==sizeof(char) may not be true:
	std::copy(str.begin(),str.end(),param);
	return param;
}