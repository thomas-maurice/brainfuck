#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def nchars(n,c):
	s = ""
	for i in range(0, n):
		s += c
	
	return s
	
if __name__ == "__main__":
	s = ""
	i = 0
	if(len(sys.argv) == 2):
		s = sys.argv[1]
	else:
		print sys.argv[0], "\"chaine\""
		sys.exit(1)
	b = ">"
	
	for k in s:
		fac = int(ord(k)/10)
		rem = ord(k)%10
		b += ">"
		b += nchars(fac, '+')
		b += "[<++++++++++>-]<"
		b += nchars(rem, '+')
		if i != (len(s)-1):
			b += ">"
		i=i+1
	
	b += "[<]>"
	b += "[.>]"
	print b
	
	
