TARGET = lab.exe
CC = gcc

.PHONY: edit run clean install uninstall valgrind

edit: $(TARGET)		 
	
lab5.o: lab7.c
				$(CC) -c lab7.c

a.out: lab7.c
	gcc -g lab7.c

$(TARGET): lab7.o 
				$(CC) -o $(TARGET) lab7.o
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