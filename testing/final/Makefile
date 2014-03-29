main: search index
	mv -t . pa4/search pa3/index
search: pa4/load.c pa4/loadFunctions.c pa4/loadFunctions.h pa4/poll.c pa4/logic.c pa4/logic.h pa4/sorted-list.c pa4/sorted-list.h pa4/process.c pa4/process.h
	clear
	gcc -o search pa4/load.c pa4/loadFunctions.c pa4/loadFunctions.h pa4/poll.c pa4/logic.c pa4/logic.h pa4/sorted-list.c pa4/sorted-list.h pa4/process.c pa4/process.h

index: pa3/recurse.c pa3/process.c pa3/process.h pa3/sl.h pa3/sorted-list.c pa3/sorted-list.h pa3/uthash.h
	clear
	gcc -o index pa3/recurse.c pa3/process.c pa3/process.h pa3/sl.h pa3/sorted-list.c pa3/sorted-list.h pa3/uthash.h


