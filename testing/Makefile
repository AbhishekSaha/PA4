main: getToken.c
	clear
	gcc -o token getToken.c
	./token test.txt

debug:
	clear
	gcc -g getToken.c
	gdb a.out

path: loadFunctions.c
	clear
	gcc -o path loadFunctions.c
	./path path.txt

dpath:
	clear
	gcc -g loadFunctions.c
	gdb a.out

lines:
	clear
	gcc -o lines fgets.c
	./lines lines.txt

load: load.c loadFunctions.c loadFunctions.h
	clear 
	gcc -o load load.c loadFunctions.c loadFunctions.h
	./load tests/Test6.txt
	./load tests/Test7.txt
	./load tests/Test8.txt
	./load tests/Test10.txt
	./load tests/Test11.txt
	./load tests/Test12.txt
	./load tests/Test13.txt
	./load tests/Test14.txt
	./load tests/Test16.txt

dload: load.c loadFunctions.c loadFunctions.h
	clear
	gcc -g load.c loadFunctions.c loadFunctions.h
	gdb a.out
