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
 
#include <help.h>

using namespace std;

void help() {
  cout << "brainfuck : just a brainfuck interpreter." << endl;
  cout << "\tAuthor: Thomas Maurice" << endl;
  cout << "\tVersion: " << VMAJOR << "." << VMINOR << " " << PLATEFORM << endl;
  cout << "\tType `brainfuck -h` for more" << endl;
}

void ext_help() {
  cout << "brainfuck : just a brainfuck interpreter." << endl;
  cout << "\tAuthor: Thomas Maurice" << endl;
  cout << "\tVersion: " << VMAJOR << "." << VMINOR << " " << PLATEFORM << endl << endl;
  cout << "Syntax: brainfuck [-h|-s|-v] <script>" << endl;
  cout << "\t-h option displays this help" << endl;
  cout << "\t-v starts a script in verbose mode" << endl;
  cout << "\t-s option provides help on the brainfuck language" << endl;
  cout << "\trunning the program passing it a script name will make it run the script" << endl;
}

void syntax_help() {
cout << "As Wikipedia says :" << endl << endl;
  cout << "The language consists of eight commands, listed below. A brainfuck\
 program is a sequence of these commands, possibly interspersed with other\
 characters (which are ignored). The commands are executed sequentially,\
 except as noted below; an instruction pointer begins at the first command,\
 and each command it points to is executed, after which it normally moves\
 forward to the next command. The program terminates when the instruction\
 pointer moves past the last command." << endl;
 
  cout << endl << "Here are the commands" << endl;
  cout << "Command | Action" << endl;
  cout << setfill('-') << setw(17) << " " << endl;
  cout << "    >   | Increment the data pointer (to point to the next cell to the right)." << endl;
  cout << "    <   | Decrement the data pointer (to point to the next cell to the left)." << endl;
  cout << "    +   | Increment (increase by one) the byte at the data pointer." << endl;
  cout << "    -   | Decrement (decrease by one) the byte at the data pointer." << endl;
  cout << "    .   | Output the byte at the data pointer." << endl;
  cout << "    ,   | Accept one byte of input, storing its value in the byte at the data pointer." << endl;
  cout << "    [   |	If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command." << endl;
  cout << "    ]   | If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command." << endl;
  
  cout << endl << "In addition, this interpreter provides you two more commands :" << endl;
  cout << "\t@: which sets a breakpoint and waits for the user to hit a key" << endl;
  cout << "\t$: which dumps the content of the program's stack" << endl;
}
