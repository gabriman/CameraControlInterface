#ifndef ListenerCanon_h
#define ListenerCanon_h

#include "Camera.h"
#include "EDSDK.h"
#include "EDSDKTypes.h"
#include <map>
#include <windows.h>
#include "DictionaryCanon.h"

class ListenerCanon 
{
public:
	static EdsError EDSCALLBACK handleStateEvent(EdsStateEvent inEvent,EdsUInt32 inParam,EdsVoid* inContext);
	static EdsError EDSCALLBACK handlePropertyEvent(EdsPropertyEvent inEvent,EdsUInt32 inPropertyID,EdsUInt32 inParam,EdsVoid* inContext);
	static EdsError EDSCALLBACK handleObjectEvent(EdsObjectEvent inEvent, EdsBaseRef  object, EdsVoid * context) ;
	static bool runThreadObserver();
	static DWORD WINAPI dispathMsg(LPVOID lpParam);
	static DWORD WINAPI dispathMsgLoop(LPVOID lpParam);

private:
};

#endif /* ListenerCanon_h */