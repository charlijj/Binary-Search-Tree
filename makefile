
all: lab4x lab4g

lab4x: lab4.o KV.o
	g++ -Wall -Wextra lab4.o KV.o -o lab4x

lab4.o: lab4.cpp lab4.h KV.h
	g++ -Wall -Wextra -c lab4.cpp -o lab4.o

KV.o: KV.cpp KV.h
	g++ -Wall -Wextra -c KV.cpp -o KV.o

lab4g: lab4g.o KVg.o
	g++ -g -Wall -Wextra lab4g.o KVg.o -o lab4g

lab4g.o: lab4.cpp lab4.h KV.h
	g++ -g -Wall -Wextra -c lab4.cpp -o lab4g.o

KVg.o: KV.cpp KV.h
	g++ -g -Wall -Wextra -c KV.cpp -o KVg.o

.PHONY: clean
clean:
	rm -f KV.o KVg.o lab4.o lab4g.o lab4x lab4g

