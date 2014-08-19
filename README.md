CameraControlInterface
======================

Interface used in the Matlab Toolbox Project

Hoy en díaa, la utilización de cámaras fotogrícas junto a un procesamiento por ordenador se ha convertido en un elemento imprescindible para realizar muchos proyectos de
investigación y artísticos. La necesidad de tomar fotografías en un momento determinado de la ejecucion de los citados proyectos hace que sea cómodo y útil poder realizar estas
fotografías desde el mismo entorno de ejecución del proyecto.

Por otra parte, la herramienta de software matemático Matlab es una de las más utilizadas para el procesamiento de imágenes, ya que su manera de trabajar está orientada a
matrices, consiguiendo mejor rendimiento que otras herramientas y lenguajes de programación cuando los tipos de datos son vectoriales o matriciales (y las imágenes son matrices de
valores). Además, el propio entorno de desarrollo Matlab incluye diversos toolbox (conjuntos de herramientas) entre los que se incluyen varios para el procesamiento y visualización
de imágenes, facilitando la labor del usuario y del desarrollador.

Por este motivo, este proyecto pretende crear herramientas de Matlab que faciliten al
desarrollador de software la creación de aplicaciones o scripts que interactuen con cámaras réflex de las dos marcas líderes en este mercado, Canon y Nikon.

Para ello, se proporciona un programa de bajo nivel que crea un interfaz con una cámara, el cual permite la comunicación usuario-cámara mediante archivos XML. También se crea
un toolboox de Matlab con funciones para interactuar con estas cámaras mediante la modificación de ficheros, con la ventaja de que está desarrollado para ser independiente de
la cámara, por lo que se utilizarán sin necesidad de conocer la cámara conectada (siempre que esté dentro de la lista de cámaras soportadas).

La arquitectura que hemos adoptado para realizar el proyecto nos proporciona la posibilidad de ampliarlo sustituyendo el toolbox de Matlab anteriormente mencionado por
otra herramienta o interfaz que pueda leer y escribir en ficheros de texto en formato XML.

Esto es posible porque hemos creado un programa intermedio entre el usuario y el SDK de la cámara correspondiente que gestiona las órdenes que le llegan desde la aplicación del
usuario mediante un archivo de texto. Este programa monitoriza cambios en dicho archivo que interpreta como nuevas órdenes que envía a la cámara. El resultado de la ejecución
de cada orden se escribiría en un fichero XML de salida. Por lo tanto, sea cual sea el interfaz que el usuario utilice para comunicarse con la cámara, este solamente haría lecturas
y escrituras en ficheros, mientras el programa intermedio se encargaría del procesamiento de estos ficheros y control de la cámara.

Este proyecto incluiría los repositorios (del mismo usuario):
CameraControl_MatlabToolbox (Toolbox que utiliza esta interfaz)
cameraSimpleControlApp (Programa de ejemplo para controlar una cámara que utiliza el toolbox)
cameraHDR (Programa de ejemplo para hacer imágenes HDR que utiliza el toolbox)
cameraTimeLapser (Programa de ejemplo para hacer videos timelapse que utiliza el toolbox)
