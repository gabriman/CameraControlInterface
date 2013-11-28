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

#ifndef CameraNikon_h
#define CameraNikon_h

#include "Camera.h"

#ifdef __cplusplus  
    extern "C" {     
	#endif  
	//Include Nikon
	#include	<stdlib.h>
	#include	<stdio.h>
	#include	"maid3.h"
	#include	"maid3d1.h"
	#include	"CtrlSample.h"

	#ifdef __cplusplus  
     }  
#endif

class CameraNikon: public Camera
{
public:
	CameraNikon();
	ResponseMsg init();
	ResponseMsg operacion1();
	ResponseMsg close();
	ResponseMsg takePicture();
	ResponseMsg getProperty(string prop);
	ResponseMsg setProperty(string prop, const char * value);
	ResponseMsg getGetList(string prop);
	ResponseMsg setTargetSave();
//	LPMAIDEntryPointProc pMAIDEntryPoint;
private:
//	unsigned long cameraID;
	tagRefObj* pRefMod;
	tagRefObj* pRefSrc;
	ULONG	ulModID;
	ULONG	ulSrcID;
	string saveTo;
};

#endif /* CameraNikon_h */