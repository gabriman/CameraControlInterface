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

#ifndef ListenerCanon_h
#define ListenerCanon_h

#include "Camera.h"
#include "EDSDK.h"
#include "EDSDKTypes.h"
#include <map>
#include <windows.h>
#include "DictionaryCanon.h"
#include "CameraCanon.h"
#include <iostream>
#include <fstream>
#include <time.h>

class ListenerCanon 
{
public:
	static EdsError EDSCALLBACK handleStateEvent(EdsStateEvent inEvent,EdsUInt32 inParam,EdsVoid* inContext);
	static EdsError EDSCALLBACK handlePropertyEvent(EdsPropertyEvent inEvent,EdsUInt32 inPropertyID,EdsUInt32 inParam,EdsVoid* inContext);
	static EdsError EDSCALLBACK handleObjectEvent(EdsObjectEvent inEvent, EdsBaseRef  object, EdsVoid * context);
	//static bool runThreadObserver();
	//static DWORD WINAPI dispathMsg(LPVOID lpParam);
	//static DWORD WINAPI dispathMsgLoop(LPVOID lpParam);

};

#endif /* ListenerCanon_h */