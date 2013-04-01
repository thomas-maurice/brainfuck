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

#include <debug.h>

using namespace std;

void stack_dump(vector<long>* tape) {
  cout << "+-----------------------------+" << endl;
  cout << "|         STACK DUMP          |" << endl;
  cout << "+-----------------------------+" << endl;
  cout << endl;
  for(unsigned int i = 0; i < tape->size(); i++)
  {
    cout << "Cell: " << setw(7) << i << " Value: " << setw(7) << (int)tape->at(i) << endl;
  }
  cout << endl;
  cout << "+-----------------------------+" << endl;
  cout << "|      END OF STACK DUMP      |" << endl;
  cout << "+-----------------------------+" << endl;
}

void breakpoint(long codepointer) {
  cout << "Breakpoint - Code position: " << codepointer << endl;
  cout << "Hit any key." << endl;
}
