#include "CameraNikon.h"


#ifdef __cplusplus  
extern "C" {     
#endif  

	LPMAIDEntryPointProc	g_pMAIDEntryPoint = NULL;
	UCHAR	g_bFileRemoved = false;
	ULONG	g_ulCameraType = 0;	// CameraType
	HINSTANCE	g_hInstModule = NULL;


#ifdef __cplusplus  
}  
#endif



CameraNikon::CameraNikon(){
	pRefSrc = NULL;
	pRefMod = NULL;
}

ResponseMsg CameraNikon::init(){
	cout<<"Camera inicializada NIKON"<<endl;

	char	ModulePath[MAX_PATH];

	LPRefObj RefItm = NULL, pRefDat = NULL;
	//char	buf[256];
	ulModID = 0;
	//UWORD	wSel;
	BOOL	bRet;

	// Search for a Module-file like "Type0003.md3".
	bRet = Search_Module( ModulePath );
	if ( bRet == false ) {
		puts( "\"Type0003 Module\" is not found.\n" );
	}
	// Load the Module-file.
	bRet = Load_Module( ModulePath );
	if ( bRet == false ) {
		puts( "Failed in loading \"Type0003 Module\".\n" );
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
	}

		// Allocate memory for reference to Module object.
	pRefMod = (LPRefObj)malloc(sizeof(RefObj));
	if ( pRefMod == NULL ) {
		puts( "There is not enough memory." );
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
	}
	InitRefObj( pRefMod );

	// Allocate memory for Module object.
	pRefMod->pObject = (LPNkMAIDObject)malloc(sizeof(NkMAIDObject));
	if ( pRefMod->pObject == NULL ) {
		puts( "There is not enough memory." );
		if ( pRefMod != NULL )	free( pRefMod );
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
	}

	//	Open Module object
	pRefMod->pObject->refClient = (NKREF)pRefMod;
	bRet = Command_Open(	NULL,					// When Module_Object will be opend, "pParentObj" is "NULL".
								pRefMod->pObject,	// Pointer to Module_Object 
								ulModID );			// Module object ID set by Client
	if ( bRet == false ) {
		puts( "Module object can't be opened.\n" );
		if ( pRefMod->pObject != NULL )	free( pRefMod->pObject );
		if ( pRefMod != NULL )	free( pRefMod );
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
	}

	//	Enumerate Capabilities that the Module has.
	bRet = EnumCapabilities( pRefMod->pObject, &(pRefMod->ulCapCount), &(pRefMod->pCapArray), NULL, NULL );
	if ( bRet == false ) {
		puts( "Failed in enumeration of capabilities." );
		if ( pRefMod->pObject != NULL )	free( pRefMod->pObject );
		if ( pRefMod != NULL )	free( pRefMod );
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
	}

	//	Set the callback functions(ProgressProc, EventProc and UIRequestProc).
	bRet = SetProc( pRefMod );
	if ( bRet == false ) {
		puts( "Failed in setting a call back function." );
		if ( pRefMod->pObject != NULL )	free( pRefMod->pObject );
		if ( pRefMod != NULL )	free( pRefMod );
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
	}

	//	Set the kNkMAIDCapability_ModuleMode.
	if( CheckCapabilityOperation( pRefMod, kNkMAIDCapability_ModuleMode, kNkMAIDCapOperation_Set )  ){
		bRet = Command_CapSet( pRefMod->pObject, kNkMAIDCapability_ModuleMode, kNkMAIDDataType_Unsigned, 
										(NKPARAM)kNkMAIDModuleMode_Controller, NULL, NULL);
		if ( bRet == false ) {
			puts( "Failed in setting kNkMAIDCapability_ModuleMode." );
			return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
		}
	}


	ulSrcID = 0;	// 0 means Device count is zero. 
	bRet = SelectFirstSource( pRefMod, &ulSrcID );
	if ( bRet == false ) return ResponseMsg(CAMERROR_CAMERA_NOT_CONECTED,"Camera not conected");


	pRefSrc = GetRefChildPtr_ID( pRefMod, ulSrcID );
	if ( pRefSrc == NULL ) {
		// Create Source object and RefSrc structure.
		if ( AddChild( pRefMod, ulSrcID ) == true ) {
			printf("Source object is opened.\n");
		} else {
			printf("Source object can't be opened.\n");
			return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Source object can't be opened.");
		}
		pRefSrc = GetRefChildPtr_ID( pRefMod, ulSrcID );
	}

	// Get CameraType
	Command_CapGet( pRefSrc->pObject, kNkMAIDCapability_CameraType, kNkMAIDDataType_UnsignedPtr, (NKPARAM)&g_ulCameraType, NULL, NULL );


	NkMAIDString stString;
	bRet = Command_CapGet( pRefSrc->pObject, kNkMAIDCapability_AcceptDiskAcquisition, kNkMAIDCapType_Generic, (NKPARAM)&stString, NULL, NULL );
	//stString.str,"C:\\");
	bRet = Command_CapSet( pRefSrc->pObject, kNkMAIDCapability_AcceptDiskAcquisition, kNkMAIDCapType_Generic, (NKPARAM)"C:\\",  NULL, NULL );
	if ( bRet == false )
		printf("Error asignando directorio");

	return ResponseMsg(CAMERROR_OK,"");
}

ResponseMsg CameraNikon::operacion1(){

	cout<<"Haciendo operacion 1  NIKON"<<endl;
	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
}

ResponseMsg CameraNikon::close(){
	// Close Module_Object
	BOOL	bRet;
	bRet = Close_Module( pRefMod );
	if ( bRet == false )
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Module object can not be closed.");
	else
		return ResponseMsg(CAMERROR_OK,"");
}

ResponseMsg CameraNikon::takePicture()
{
	BOOL	bRet;
	bRet = IssueProcess( pRefSrc, kNkMAIDCapability_Capture );
	Command_Async( pRefSrc->pObject );
	if (bRet == false)
		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"Error taking photo");

	//Save photo
	ULONG	ulItemID = 0;
	ulItemID = 0;
	ULONG	ulDataType = 0;

	bRet = SelectFirstItem( pRefSrc, &ulItemID );
	if( bRet == true && ulItemID > 0 ){
			// FROM ItemCommandLoop
			LPRefObj	pRefItm = NULL;
			pRefItm = GetRefChildPtr_ID( pRefSrc, ulItemID );
			if ( pRefItm == NULL ) {
				// Create Item object and RefSrc structure.
				if ( AddChild( pRefSrc, ulItemID ) == true ) {
					printf("Item object is opened.\n");
				} else {
					printf("Item object can't be opened.\n");
				}
				pRefItm = GetRefChildPtr_ID( pRefSrc, ulItemID );
			}
			ulDataType = kNkMAIDDataObjType_Image;
			g_bFileRemoved = false;
			
			
			// FUNCTION bRet = ImageCommandLoop( pRefItm, ulDataType );
			// FROM ImageCommandLoop	
				LPRefObj	pRefDat = NULL;
				pRefDat = GetRefChildPtr_ID( pRefItm, ulDataType );
				if ( pRefDat == NULL ) {
					// Create Image object and RefSrc structure.
					if ( AddChild( pRefItm, ulDataType ) == true ) {
						printf("Image object is opened.\n");
					} else {
						printf("Image object can't be opened.\n");
					}
					pRefDat = GetRefChildPtr_ID( pRefItm, ulDataType );
				}

				bRet = IssueAcquire( pRefDat );



			// If the image data was stored in DRAM, the item has been removed after reading image.
			if ( g_bFileRemoved ) {
				RemoveChild( pRefSrc, ulItemID );
				pRefItm = NULL;
			}

			if ( pRefItm != NULL ) {
		// If the item object remains, close it and remove from parent link.
		bRet = RemoveChild( pRefSrc, ulItemID );
	}


	}
	
	return ResponseMsg(CAMERROR_OK,"");
}

ResponseMsg CameraNikon::getProperty(string prop)
{
	char* value;
	BOOL bRet;

	//if		(!prop.compare("ISO")) prop = kEdsPropID_ISOSpeed;
	if (!prop.compare("SPEED")) bRet = GetEnumCapability( pRefSrc, kNkMAIDCapability_ShutterSpeed, &value);
	else if (!prop.compare("APERTURE")) bRet = GetEnumCapability( pRefSrc, kNkMAIDCapability_Aperture, &value);
	else if (!prop.compare("ISO")) bRet = GetEnumCapability( pRefSrc, kNkMAIDCapability_Sensitivity, &value);
	else return ResponseMsg(CAMERROR_PROP_UNAVALIABLE,"Property not supported");

	if (strcmp(value,"")==0) return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");

	return ResponseMsg(CAMERROR_OK,value);
};

ResponseMsg CameraNikon::setProperty(string prop, const char * value)
{
	int propEds = 0;
	BOOL bRet;
	//if		(!prop.compare("ISO")) propEds = kEdsPropID_ISOSpeed;
	if (!prop.compare("SPEED")) bRet = SetEnumCapability( pRefSrc, kNkMAIDCapability_ShutterSpeed, value);
	else if (!prop.compare("APERTURE")) bRet = SetEnumCapability( pRefSrc, kNkMAIDCapability_Aperture, value);
	else if (!prop.compare("ISO")) bRet = SetEnumCapability( pRefSrc, kNkMAIDCapability_Sensitivity, value);
	else return ResponseMsg(CAMERROR_PROP_UNAVALIABLE,"Property not supported");

	if (bRet==false) return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");

	return ResponseMsg(CAMERROR_OK,"");
}


ResponseMsg CameraNikon::getGetList(string prop)
{	
	char* value;
	BOOL bRet;
	//if		(!prop.compare("ISO")) propEds = kEdsPropID_ISOSpeed;
	if (!prop.compare("SPEED")) bRet = GetListEnumCapability( pRefSrc, kNkMAIDCapability_ShutterSpeed, &value);
	else if (!prop.compare("APERTURE")) bRet = GetListEnumCapability( pRefSrc, kNkMAIDCapability_Aperture, &value);
	else if (!prop.compare("ISO")) bRet = GetListEnumCapability( pRefSrc, kNkMAIDCapability_Sensitivity, &value);
	else return ResponseMsg(CAMERROR_PROP_UNAVALIABLE,"Property not supported");

	if (bRet==false) return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");

	//const char * valueTranslate = dictionary.translate(prop,edsValue);
	//if (valueTranslate=="unknown") return ResponseMsg(CAMERROR_VALUE_UNKNOWN,"Value unknown");

	return ResponseMsg(CAMERROR_OK,value);
};

ResponseMsg CameraNikon::setTargetSave()
{
	//In Nikon it's not necessary
	return ResponseMsg(CAMERROR_OK,"");
}