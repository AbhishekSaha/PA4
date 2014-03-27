main: load.c loadFunctions.c loadFunctions.h poll.c poll.h logic.c logic.h sorted-list.c sorted-list.h process.c process.h
	clear 
	gcc -o load load.c loadFunctions.c loadFunctions.h poll.c poll.h logic.c logic.h sorted-list.c sorted-list.h process.c process.h
	./load tests/Test6.txt
	rm load

dload: load.c loadFunctions.c loadFunctions.h poll.c poll.h logic.c logic.h sorted-list.c sorted-list.h process.c process.h
	clear
	gcc -g load.c loadFunctions.c loadFunctions.h poll.c poll.h logic.c logic.h sorted-list.c sorted-list.h process.c process.h
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

error: load.c loadFunctions.c loadFunctions.h poll.c poll.h logic.c logic.h sorted-list.c sorted-list.h process.c process.h
	clear 
	gcc -o load load.c loadFunctions.c loadFunctions.h poll.c poll.h logic.c logic.h sorted-list.c sorted-list.h process.c process.h
	./load  sup
	rm load

