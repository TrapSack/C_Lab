TARGET = lab.exe
CC = gcc

.PHONY: edit run clean install uninstall valgrind

edit: $(TARGET)		 
	
lab5.o: lab6.c
				$(CC) -c lab6.c

a.out: lab6.c
	gcc -g lab6.c

$(TARGET): lab6.o 
				$(CC) -o $(TARGET) lab6.o
valgrind: a.out
	valgrind -q ./a.out	
	
splint:
	splint *.c
clean:
			@rm -rf $(TARGET) *.o *.i *.s *.gch *.out *.exe
install: $(TARGET) 
			install $(TARGET) /
run:
			$(TARGET)
uninstall:
			@rm -rf /$(TARGET)