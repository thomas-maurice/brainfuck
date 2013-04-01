#include <iostream>
#include <cstdlib>

#define GROUP 10

using namespace std;

string n_chars(int n, char c) {
	string r = "";
	for(unsigned int i = 0; i < n; i++)
		r += c;
	
	return r;
}

int main(int argc, char **argv) {
	if(argc != 2) {
		cout << argv[0] << " <string to brainfuckize>" << endl;
		return EXIT_FAILURE;
	}
	
	string s = argv[1];
	
	cout << ">";
	
	for(unsigned int i = 0; i < s.size(); i++) {
		int fac = s.at(i) / GROUP;
		int rem = s.at(i) % GROUP;
		cout << ">";
		cout << n_chars(fac, '+');
		cout << "[<" << n_chars(GROUP, '+') << ">-]<";
		cout <<  n_chars(rem, '+');
		if(i != (s.size()-1))
			cout << ">";
	}
	
	cout << "[<]>[.>]" << endl;
	
	
	return EXIT_SUCCESS;
}
