/*
Program that takes a directory's path and creates a json file that contains the 
name and size of each file in the directory.
*/

#include <iostream>
#include <boost/filesystem.hpp>
#include <string>
#include <algorithm>
#include "json/writer.h"
#include <fstream>
using std::cout;
using namespace boost::filesystem;


void write_in_json(path p) {
	/*
	This function collects the files information from the given path, 
	creates the json file and save it in the directory's path.
	*/
	std::vector<path> files_direc;

	for (auto&& x : directory_iterator(p)) {
		//We iterate over the elemets in the directory and, if
		//the element is a file, we save it's path.
		if (is_regular_file(x))
				files_direc.push_back(x.path());
	}
	//We sort the files by alphabetic order
	std::sort(files_direc.begin(), files_direc.end());


	//Our key value for the json object
	Json::Value key_obj;
	//Where we'll save the files' paths
	Json::Value files_paths(Json::arrayValue);
	//We use this object to save each file's data in the array
	Json::Value item;
	for(auto&& x: files_direc)
	{
		//For each element in list of files, we took it's information
		//and save it in the vec array
		item["name"] = x.filename().generic_string();
		item["size"] = file_size(x);
		files_paths.append(item);
	}
	key_obj["files"] = files_paths;

	std::ofstream file_id;
	//We use the directory's path to create the dir.json file there
	p /= "dir.json";
	file_id.open(p.generic_string());
	//Use jsoncpp library to write the data in dir.json file.
	Json::StyledWriter styledwriter;
	file_id << styledwriter.write(key_obj);
	file_id.close();
}


int main(int argc, char* argv[]) {

	//If we don't have the directory's path, we return an error message.
	if (argc < 2)
	{
		cout << "There are not enough arguments. Type the program's" << std::endl;
		cout << "name (listdir), and the folder's path." << std::endl;
		return -1;
	}

	//We create a path object with the given folder's path
	path p(argv[1]);

	//If the path have spaces (for example, C:/my name/docs), we concatenate the strings
	if (argc > 2) {
		for (int idx = 2; idx < argc; idx++) {
			p += " ";
			p += argv[idx];
		}
	}

	try
	{
		//We check if the path exists
		if (exists(p))
		{
			//We check if the path is a directory
			if (is_directory(p)) 
				write_in_json(p);
			else
				cout << "The path is not a directory" << std::endl;
		}
		else
			cout << "The directory doesn't exist." << std::endl;
	}
	//Thrown if the user's account doesn't have access to the given path
	catch (const filesystem_error& ex)
	{
		cout << "Error in the directory" << std::endl;
		cout << ex.what() << std::endl;
	}

	return 0;
}