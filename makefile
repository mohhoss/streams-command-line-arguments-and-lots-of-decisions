CC=g++
main:   main.o  process_data.o
        $(CC)   -Wall   -g      main.o  process_data.o  -o      main
main.o: main.cc main.h  process_data.h
        $(CC)   -Wall   -c      main.cc
process_data.o: process_data.cc process_data.h
        $(CC)   -Wall   -c      process_data.cc
clean:
        rm      *.o
