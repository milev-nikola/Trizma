#include<iostream>
#include<fstream>
#include<string>
#include<exception>

bool SearchFile(std::string line) {
	std::ifstream file;
	file.open("log.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			std::string buff = "";
			std::getline(file, buff, '\n');
			if (!line.compare(buff))
				return true;

		}
	}
	else
		throw std::exception("file not opened");

	return false;
	
}


int main() {
	
	try {
		std::cout << SearchFile("FOUNDED!") << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}