CC = gcc
CC_FLAGS = -g -Wall -ansi -pedantic
OUT_EXE = coPlot
FILES = coPlot.o

build:$(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

clean:
	rm $(OUT_EXE) *.o *.exe