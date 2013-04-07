#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
	if(argc == 1) {
		cout << argv[0] << " <filename.b>" << endl;
		return EXIT_FAILURE;
	}
	ifstream inf(argv[1], ios::in);
	if(!inf) {
		cout << "Error : Cannot open file" << endl;
		return EXIT_FAILURE;
	}
	string code;
	string line;
	string curline;
	int indentlevel = 0;
	
	while(getline(inf, line)) {
		code += line;
	}
	
	
	inf.close();
	
	for(unsigned long i = 0; i < code.size(); i++) {
		if(code.at(i) == '[') {
			cout << setw(indentlevel*4) << "" << curline << endl << setw(indentlevel*4) << "" << '[' << endl;
			indentlevel++;
			curline = "";
		} else if (code.at(i) == ']') {
			cout << setw(indentlevel*4) << "" << curline << endl;
			indentlevel--;
			cout << setw((indentlevel)*4) << "" << ']' << endl;
			curline = "";
		} else {
			curline += code.at(i);
		}
	}
			
	#ifdef WIN32
  	system("pause");
  #endif
	return EXIT_SUCCESS;
}
