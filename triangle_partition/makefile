CC = g++
STD = -std=c++20
RELEASE = -O2 -mtune=native -march=native -flto
PROG = triangle

$(PROG): main.o triangle.o
	$(CC) $(STD) $(RELEASE) main.o triangle.o -o triangle

triangle.o: triangle.cpp
	$(CC) $(STD) $(RELEASE) -c triangle.cpp -o triangle.o

main.o: main.cpp
	$(CC) $(STD) $(RELEASE) -c main.cpp -o main.o

clean:
	rm *.o *.out $(PROG)

run: $(PROG)
	./problemgen.py | ./$(PROG) | ./plot.py
