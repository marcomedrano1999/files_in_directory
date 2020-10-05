# Listdir
Este programa toma una ruta de un directorio y crea un archivo json que contiene los nombres y el tamaño de los archivos que se encuentran en la ruta dada.

## Comenzando
### Prerequisitos
Este programa utiliza dos paquetes externos: Boost and Jsoncpp. Se requiere la instalación de Boost y el paquete Jsoncpp está incluido. Además, este programa requiere CMake para
crear el proyecto en tu IDE y OS. 
### Instalación
CMake se puede instalar siguiendo los pasos que se mencionan en la pagina oficial:

https://cmake.org/install/

Boost se puede instalar en el siguiente link:

https://www.boost.org/doc/libs/1_55_0/doc/html/bbv2/installation.html

Tambien se puede instalar Jsoncpp en el siguiente link:

https://github.com/open-source-parsers/jsoncpp

Por último, para descargar este proyecto introduzca lo siguiente en su programa de linea de comandos:

```git clone https://github.com/marcomedrano1999/files_in_directory.git```

Para crear la carpeta del proyecto, copia la ruta del directorio donde se descargaron los documentos, abre CMake y pégala en el cuadro a la izquierda de la etiqueta 
"Where is the source code:". Haz lo mismo con el cuadro abajo de este, pero agregando a final lo siguiente: /Build. Da click en el boton "Configure" (se deben de desplegar 
valores en rojo en el cuadro arriba del mencionado boton) y despues da click en el boton "Generate". Una explicación más detallada se puede encontrar en el siguiente video:

https://www.youtube.com/watch?v=wl2Srog-j7I&list=PLpHIphr3laQZxwrehzusWud6nEyym8SJ2&index=1

## ¿Cómo funciona?
Para empezar, usamos la libreria filesystem incluida en el paquete Boost para verificar si la ruta del directorio dado es en realidad un directorio. Si lo es, pasamos a extraer los
nombres y tamaños de los archivos contenidos en este, para despues ordenarlos alfabeticamente.

Con jsoncppp creamos un objeto Json y guardamos los datos en él. Finalmente, usamos styledwriter para escribir los datos en el archivo json, el cual lo creamos en el directorio
dado.

### Entrada
Para ejecutar este programa en la linea de comandos introduzca ```listdir path```, donde path es la ruta del directorio que deseamos analizar.

### Salida
Este programa crea un archivo Json que contiene los nombres y tamaños en bytes de los archivos del directorio dado. Un ejemplo del archivo generado se muestra a continuación.
{ "files": [
 {"name":"texto1.txt","size":450},
 {"name":"texto2.txt","size":950}]}  

Si la ruta introducidad no existe o no es un directorio, el programa retorna -1. 


## Elaborado con
IDE: Visual Studio 2017

CMake version: 3.18.3

Boost version: 1.73.0

Jsoncpp

## Autor
**Marco Medrano**

## Agradecimientos
Creadores del paquete Boost.

Creadores del paquete jsoncpp.

Comunidad de Stack overflow.


