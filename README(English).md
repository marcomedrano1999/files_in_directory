# Listdir
This program creates a Json file that contains the names and sizes of the files in the given directory.

## Getting Started
### Prerequites
This program uses two external packages: Boost and Jsoncpp. Boost is required and Jsoncpp is included in the files. Also, this program requires CMake to create the proyect in 
your IDE.
### Installing
You can install CMake following the steps explained in the official page:

https://cmake.org/install/

You can download Boost in the following link:

https://www.boost.org/doc/libs/1_55_0/doc/html/bbv2/installation.html

You can download Jsoncpp in the following link:

https://github.com/open-source-parsers/jsoncpp

You can download this project by running the following comand

```git clone https://github.com/marcomedrano1999/files_in_directory.git```

Open CMake and paste the project's path in the "Where is the source code", then paste it again in "Where to build binaries" and add "/Build" at the end. 
Once you've done this, click in the "Configure" button, it must display red values. Finally, click in the Generate botton, and select your favorite IDE.
A better explanation can be found in the next video:

https://www.youtube.com/watch?v=wl2Srog-j7I&list=PLpHIphr3laQZxwrehzusWud6nEyym8SJ2&index=1

## How does it work?
First of all, we use filesystem library from the Boost package to verify if the given path is a directory, then we extrac the files' data, save it in a path vector and sorted by alphabetical order. 

With Jsoncpp we create the Json object and save the data in it. Finally, use styledwriter to write the data in the json file (located in the given path).

### Inputs
To execute this program in the command line we type ```listdir path```, where path is the path of the directory we want to analyse.

### Outputs
This program creates a Json file that contains the name and size of the files in the given directory in the following form:
{ "files": [
 {"name":"text1.txt","size":450},
 {"name":"text2.txt","size":950}]}  

If the path is not given or if it's not a directory, the program returns -1. 


## Build with
IDE: Visual Studio 2017

CMake version: 3.18.3

Boost version: 1.73.0

## Author 
**Marco Medrano**

## Acknowledgments
Creators of the Boost package

Creators of the jsoncpp package

Stack overflow community

