main: load.c loadFunctions.c loadFunctions.h poll.c poll.h
	clear 
	gcc -o load load.c loadFunctions.c loadFunctions.h poll.c poll.h
	./load tests/Test6.txt
	rm load

dload: load.c loadFunctions.c loadFunctions.h poll.c poll.h
	clear
	gcc -g load.c loadFunctions.c loadFunctions.h poll.c poll.h
	gdb a.out

poll: poll.c
	clear
	gcc -o poll poll.c poll.h
	./poll
	rm poll

dpoll:
	clear
	gcc -g poll.c
	gdb a.out
