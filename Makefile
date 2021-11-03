CC = gcc
AR = ar
FLAGS = -Wall -g

all: loops recursives recursived loopd maindloop maindrec mains

maindloop: main.o libclassloops.so NumClass.h
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so NumClass.h
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

mains: main.o libclassrec.a NumClass.h
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm

#static lib, none recursive
loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a
	
#static lib, recursive at advanced files
recursives: libclassrec.a
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a

#dynamic lib, recursive at advanced files
recursived: libclassrec.so 
libclassrec.so: basicClassification.o advancedClassificationRecursion.o 
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o 

#dynamic lib, none recursive
loopd: libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o 
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

#compilize prime && Strong
basicClassification.o: basicClassification.c
	$(CC) $(FLAGS) -c basicClassification.c 
#compilize loops func - palindrome && armstrong
advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(FLAGS) -c advancedClassificationLoop.c 
#compilize rec func - palindrome && armstrong
advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

main.o: main.c NumClass.h
	$(CC) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so maindrec maindloop mains