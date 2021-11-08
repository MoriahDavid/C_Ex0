CC=gcc
AR=ar
OBJ_MAIN=main.o
OBJ_BASIC=basicClassification.o
OBJ_LOOPS=advancedClassificationLoop.o
OBJ_RECUR=advancedClassificationRecursion.o
FLAGS= -I. -Wall

all: loops recursives recursived loopd mains maindloop maindrec 

loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so

mains: $(OBJ_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJ_MAIN) libclassrec.a -lm

maindloop: $(OBJ_MAIN) libclassloops.a
	$(CC) $(FLAGS) -o maindloop $(OBJ_MAIN) ./libclassloops.so -lm

maindrec: $(OBJ_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJ_MAIN) ./libclassrec.so -lm

libclassrec.so: $(OBJ_BASIC) $(OBJ_RECUR)
	$(CC) $(FLAGS) -shared -o libclassrec.so $(OBJ_BASIC) $(OBJ_RECUR)

libclassloops.so: $(OBJ_BASIC) $(OBJ_LOOPS)
	$(CC) $(FLAGS) -shared -o libclassloops.so $(OBJ_BASIC) $(OBJ_LOOPS)

libclassloops.a: $(OBJ_BASIC) $(OBJ_LOOPS)
	$(AR) -rcs libclassloops.a $(OBJ_BASIC) $(OBJ_LOOPS)

libclassrec.a: $(OBJ_BASIC) $(OBJ_RECUR)
	$(AR) -rcs libclassrec.a $(OBJ_BASIC) $(OBJ_RECUR)

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

basicClassification.o: basicClassification.c
	$(CC) $(FLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
