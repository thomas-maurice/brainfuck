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
		cout << argv[0] << " <int to brainfuckize>" << endl;
		return EXIT_FAILURE;
	}
	
	int i = atoi(argv[1]);
	int fac = i / GROUP;
	int rem = i % GROUP;
	
	cout << ">";
	cout << n_chars(fac, '+');
	cout << "[<" << n_chars(GROUP, '+') << ">-]<";
	cout <<  n_chars(rem, '+');

	
	return EXIT_SUCCESS;
}
