CC = g++
STD = -std=c++20
RELEASE = -O3 -mtune=native -march=native -flto
PROG = triangle

$(PROG): main.o triangle.o
	$(CC) $(STD) $(RELEASE) main.o triangle.o -o triangle

triangle.o: triangle.cpp prune_search.hpp
	$(CC) $(STD) $(RELEASE) -c triangle.cpp -o triangle.o

main.o: main.cpp prune_search.hpp
	$(CC) $(STD) $(RELEASE) -c main.cpp -o main.o

clean:
	rm *.o $(PROG)

run: $(PROG)
	./problemgen.py | ./$(PROG) | ./plot.py
