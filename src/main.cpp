/*
 *
 *	Copyright (C) 2013 Thomas MAURICE
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License along
 *	with this program; if not, write to the Free Software Foundation, Inc.,
 *	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <debug.h>
#include <help.h>

using namespace std;

int main(int argc, char** argv)
{
  // Vector containing all the brainfuck code to execute
  vector<char> code; // without comments (only '+-><.,[]$@)'
  // The turing tape containing al the cells
  vector<long> tape;
  // LIFO stack with matching bracets
  vector<long> bracets;
  // Cell pointer
  unsigned long pointer = 0;
  unsigned long steps = 0;
  // Script name
  string fname;
  // Verbose mode ?
  bool verbose = false;
  #ifdef WIN32
  	verbose = true;
  #endif
  // Pointer on the code array (instruction being executed)
  long codepointer = 0;
  
  // Loads the first celle with 0
  tape.push_back(0);
  
  // Parsing command line parameters
  if(argc < 2) {
    help();
    return EXIT_FAILURE;
  }
  
  for(int i = 0; i < argc; i++)
  {
    if(string(argv[i]) == "-v")
      verbose = true;
    else if(string(argv[i]) == string("-h")) {
      ext_help();
      return EXIT_SUCCESS;
    } else if(string(argv[i]) == string("-s")) {
      syntax_help();
      return EXIT_SUCCESS;
    }
    else
      fname = argv[i];
  }
  
  ifstream f(fname.c_str(), ios::in);
  if(!f) {
    cout << "Error, the given file (" << fname << ") couldn't be opened." << endl;
    return EXIT_FAILURE;
  }
  
  if(verbose)
    cout << "[VERBOSE] Loading \"" << fname << "\" ..." << endl;
  
  char c;
  
  while(f >> c) {
    if(c == '+' ||
       c == '-' ||
       c == '.' ||
       c == ',' ||
       c == '>' ||
       c == '<' ||
       c == '[' ||
       c == ']' ||
       c == '@' ||
       c == '*' ||
       c == '$')
    {
      code.push_back(c);
    }
  
    if(verbose)
      cout << "[VERBOSE] Loaded " << code.size() << " instructions." << "\r";
  }
  
  if(verbose)
    cout << endl;
  
  code.push_back(EOF);
  
  f.close();
  
  if(verbose)
    cout << "[VERBOSE] Instructions loaded, executing." << endl <<\
            "-----------------------------------------"<< endl;
  
  c = code.at(0);
  
  while(codepointer != code.size()) {
    switch(c) {
      case '@':
        breakpoint(codepointer);
        getchar();
        break;
      case '$':
        stack_dump(&tape);
        break;
      case '>':
        pointer++;
        if(tape.size() < pointer+1) tape.push_back(0);
        break;
      case '<':
        pointer--;
        break;
      case '-':
        tape[pointer]--;
        break;
      case '+':
        tape[pointer]++;
        break;
      case '.':
        cout << (char)tape.at(pointer);
        break;
      case '*':
        cout << (long)tape.at(pointer);
        break;
      case ',':
        cin >> tape[pointer];
        break;
      case '[':
        bracets.push_back(codepointer);
        break;
      case ']':
        if(!bracets.empty())
        {
          if(tape[pointer] != 0) codepointer = bracets.back();
          else bracets.pop_back();
        } else {
          codepointer = 0;
        }
        break;
        
    }
    
    steps++;
    codepointer++;
    if(codepointer != code.size())
    	c = code.at(codepointer);
  }
  
  if(verbose)
    cout << "----------------------------------------" << endl << \
            "[VERBOSE] Program executed successfully in " << \
            steps << " steps." << endl;
  
  #ifdef WIN32
  	system("pause");
  #endif
  
  return EXIT_SUCCESS;
}
