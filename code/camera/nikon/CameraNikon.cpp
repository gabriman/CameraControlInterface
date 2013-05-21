#include "CameraNikon.h"

CameraNikon::CameraNikon(){

}

ResponseMsg CameraNikon::init(){
	
	cout<<"Camera inicializada NIKON"<<endl;
	//char	ModulePath[MAX_PATH];

	//pRefSrc = GetRefChildPtr_ID(pRefMod, cameraID);

	 //pRefSrc = GetRefChildPtr_ID(pRefMod, cameraID);
  //      if(!pRefSrc) {
  //          // create source object and RefSrc structure
  //          if(AddChild(pMAIDEntryPoint, pRefMod, cameraID)) {
  //              cout<<"Opened source object"<<endl;
  //          } else {
  //              cout<<"Couldn't open source object";
		//		return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
  //          }
  //          pRefSrc = GetRefChildPtr_ID(pRefMod, cameraID );
		//	//QNikonCBWrapper::getInstance()->registercamera(pRefSrc, this);
  //      }


	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
}

ResponseMsg CameraNikon::operacion1(){

	cout<<"Haciendo operacion 1  NIKON"<<endl;
	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
}

ResponseMsg CameraNikon::close(){

	cout<<"Haciendo  close  NIKON"<<endl;
	return ResponseMsg(CAMERROR_ERROR_UNDEFINED,"ERROR");
}