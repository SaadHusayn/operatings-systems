first compile with -g flag so that gdb can see all the varible names

then run gdb with executable file like
gdb ./a.out

then type layout src to get your c code in front of you

then set break with a function name i.e

b main

then finally run 

to go to next line :
n or next

to go in function definition:
step




if segmentation fault occurs you can backtrace:
backtrace