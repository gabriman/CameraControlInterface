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

#ifndef CameraCanon_h
#define CameraCanon_h

#include "Camera.h"
#include "EDSDK.h"
#include "EDSDKTypes.h"
#include <map>
#include "DictionaryCanon.h"
#include "ListenerCanon.h"


class CameraCanon : public Camera
{
private:
	EdsCameraRef camera;
	EdsError err;
	bool isSDKLoaded;
	DictionaryCanon dictionary;
	bool photoDetected;
	std::string lastPhotoName;

public:
	CameraCanon();
	CameraCanon(string photosDirectory);
	ResponseMsg init();
	ResponseMsg setProperty(string prop, const char * value);
	ResponseMsg getProperty(string prop);
	ResponseMsg getGetList(string prop);
	ResponseMsg close();
	ResponseMsg takePicture();
	ResponseMsg setTargetSave();

	void setPhotoDetected(bool value);
	bool getPhotoDetected();	
	void setLastPhotoName(std::string name);
	std::string getLastPhotoName();
private:
	EdsError getFirstCamera(EdsCameraRef *camera);
	static void easyRelease(EdsBaseRef &ref){
		if(ref != NULL){
			EdsRelease(ref);
			ref = NULL;
		}
	}

};

#endif /* CameraCanon_h */