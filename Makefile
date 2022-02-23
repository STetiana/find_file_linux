# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = g++                        # compiler to use


all: find

find: find.o lib_find.a
	@echo "Creating binary"
	${CC} -o find find.o -L. -l_find

lib_find.a: find_file.o
	@echo "Creating library"
	ar rcs lib_find.a find_file.o

find_file.o: find_file.cpp
	@echo "Creating object.."
	${CC} -c find_file.cpp -o find_file.o

find.o: find.cpp
	@echo "Creating object.."
	${CC} -c find.cpp -o find.o  

clean:
	@echo "Cleaning up..."
	rm -rvf *.o find
