/*
Programa para leer los archivos de un directorio. La solucion se guarda en un archivo JSON llamado
"dir.json"
*/

#include <iostream>
#include <boost/filesystem.hpp>
#include <string>
#include <algorithm>
#include <json/writer.h>
#include <fstream>
using std::cout;
using namespace boost::filesystem;


class directory {
private:
	std::vector<path> files_direc;
public:
	directory(path p) {
		try
		{
			for (auto&& x: directory_iterator(p))
				files_direc.push_back(x.path());
			std::sort(files_direc.begin(), files_direc.end());
		}
		catch (const filesystem_error& ex)
		{
			cout << ex.what() << std::endl;
		}
	}
	bool write_in_json() {
		Json::Value written;
		Json::Value vec(Json::arrayValue);
		Json::Value item;
		for(auto&& x: files_direc)
		{
			item["name"] = x.filename().generic_string();
			item["size"] = x.size();
			vec.append(item);
		}
		written["files"] = vec;

		std::ofstream file_id;
		file_id.open("dir.json");
		Json::StyledWriter styledwriter;
		file_id << styledwriter.write(written);
		file_id.close();
		return true;
	}
};

int main(int argc, char* argv[]) {
	if (argc < 2)
	{
		cout << "Argumentos insuficientes. Introduzca el nombre de la" << std::endl;
		cout << "aplicacion y a continuacion la ruta del directorio a" << std::endl;
		cout << "analizar." << std::endl;
	}

	if (argc > 2) {
		for (int idx = 2; idx < argc; idx++)
			//argv[1] += argv[idx];
			return -1;
	}
	path p(argv[1]);
	try
	{
		if (exists(p))
		{
			if (is_directory(p)) {
				directory dir(p);
				dir.write_in_json();
			}
			else
				cout << "La ruta introducida no es un directorio." << std::endl;
		}
		else
			cout << "El directorio introducido no existe." << std::endl;
	}
	catch (const filesystem_error& ex)
	{
		cout << ex.what() << std::endl;
	}



	return 0;
}