brainfuck
=========

A simple brainfuck interpreter

##Compilation
To compile this brainfuck interpreter you need to have CMake installed. Then create
a build/ directory in the source folder then
```bash
cmake ..
make
```

Then you should have a nice brainfuck interpreter :)

##Usage
To use it you need to type ```./brainfuck scriptname.b```
If you want to run it in verbose mode, add the option -v
If you want some help type ```./brainfuck -h``` and finally ```./brainfuck -s```
to have some help about Brainfuck syntax.

##Addition to "standard" Brainfuck
In addition to the standard specification of the Brainfuck language, this interpreter
provides 3 more commands : @ which inserts a breakpoint in the program (it will
stop and wait until the user hits a key), $ which dumps the stack (the tape of
the program) and * which allows you do print the numeric value of a cell instead of the ASCII one.
