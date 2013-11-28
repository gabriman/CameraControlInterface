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

#include "ListenerCanon.h"


EdsError EDSCALLBACK ListenerCanon::handleStateEvent(
	EdsUInt32 inEvent
	,EdsUInt32 inParam
	,EdsVoid* inContext
	)
{
	cout<<"Canon: handleStateEvent detected.\n"<<endl;
	EdsError error = EDS_ERR_OK;
	switch(inEvent) {
		// Connection with camera lost (maybe power off?)
	case kEdsStateEvent_Shutdown: {
		//Canon::instance().shutdownSDK(true);
		break;	
								  }
	case kEdsStateEvent_All:{cout<<"EVENT ALL"<<endl;}
	default:break;
	};
	return error;
}


EdsError EDSCALLBACK ListenerCanon::handlePropertyEvent(
	EdsPropertyEvent inEvent
	,EdsUInt32 inPropertyID
	,EdsUInt32 inParam
	,EdsVoid* inContext)
{
	cout<<"Canon: handlePropertyEvent property.\n"<<endl;
	switch(inEvent) {
	case kEdsPropertyEvent_PropertyChanged: {
		/*
		if(inPropertyID == kEdsPropID_AvailableShots) {
		EdsUInt32 data;
		err = EdsGetPropertyData(Canon::instance().camera, kEdsPropID_AvailableShots, 0, data_size	,&data);
		printf("There are a couple of images available on the cam: %d\n", (int)inParam);
		}
		*/
		//Canon::instance().getProperty(inPropertyID);
		break;
											};

	default:break;
	};
	EdsError error = EDS_ERR_OK;
	return error ;
}



EdsError EDSCALLBACK ListenerCanon::handleObjectEvent( EdsObjectEvent inEvent, EdsBaseRef  object, EdsVoid * context)
{ 
	CameraCanon* c = (CameraCanon*)context;
	
			cout<<"handleObjectEvent"<<endl;
	switch(inEvent) 
	{ 
	case kEdsObjectEvent_DirItemRequestTransfer: 
		{
			cout<<"New photo requesting transfer"<<endl;
			c->setPhotoDetected(true);
			EdsError err = EDS_ERR_OK;
			EdsStreamRef stream = NULL;

			EdsDirectoryItemInfo dirItemInfo;
			err = EdsGetDirectoryItemInfo(object, &dirItemInfo);

			if (err == EDS_ERR_OK)
			{
				time_t     now = time(0);
				tm* localtm = localtime(&now);
				char cad[20];
				strftime( cad, 20, "%Y-%m-%d_%H-%M-%S", localtm);
				string dateAndNameFile = "";
				dateAndNameFile.append(cad);
				dateAndNameFile.append("_");
				dateAndNameFile.append(dirItemInfo.szFileName);
				
				string fullPath = "";
				fullPath.append(c->getPathSavePhotos());
				fullPath.append("\\");
				fullPath.append(dateAndNameFile);
				err = EdsCreateFileStream(fullPath.c_str(), kEdsFileCreateDisposition_CreateAlways, kEdsAccess_ReadWrite, &stream);
				// err = EdsCreateMemoryStream(0, &stream);
			}

			// Download Image
			if (err == EDS_ERR_OK)
			{
				err = EdsDownload(object,  dirItemInfo.size, stream);
			}

			if (err == EDS_ERR_OK)
			{
				err = EdsDownloadComplete(object);
			}

			//EdsImageRef imageRef = NULL;

			//if (err == EDS_ERR_OK)
			//{
			//	err = EdsCreateImageRef(stream, &imageRef);
			//}

			//EdsImageInfo imageInfo;

			//if (err == EDS_ERR_OK)
			//{
			//	err = EdsGetImageInfo(imageRef, kEdsImageSrc_FullView, &imageInfo);
			//}
			//if (err == EDS_ERR_OK)
			//{
			//	printf ("Image Width: %d\n", imageInfo.width);
			//}

			// Release stream
			if( stream != NULL)
			{
				EdsRelease(stream);
				stream = NULL;
			}

			break;
		}
	case kEdsObjectEvent_DirItemCreated:	//When is in camera mode, set only photo detected for stop to wait in takeCommand loop
		{
			// If target is camera, set photo detected
			// We do the "if" because when target is "both", will be 2 object events, and we want setPhotoDetetected once
			if (!c->getTargetPhotos().compare("camera"))	c->setPhotoDetected(true);
			break;
		}
	} 

	// Object must be released 
	if(object) 
	{ 
		EdsRelease(object); 
	} 	
	EdsError error = EDS_ERR_OK;
	return error ;
}