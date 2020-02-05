GCC = g++
GXX = $(GCC)

STD = -std=c++11
FLAGS = -Wall
ifdef DEBUG
	FLAGS += -DDEBUG
endif

# SFML = -lsfml-graphics -lsfml-window -lsfml-system

COMPILE = $(GXX) $(STD) $(FLAGS)

SRC = src
OBJ = obj
BUILDS = builds
TESTS = tests

all: compile_tests

main: 

compile_tests: test1 test2

documentation:
	mkdir -p doc && cd doc && mkdir -p doxy && doxygen Doxyfile && make -C doxy/latex && cp doxy/latex/refman.pdf doc.pdf

build_dir:
	mkdir -p $(BUILDS)

obj_dir:
	mkdir -p $(OBJ)

setup: build_dir obj_dir

# labo09.o: setup labo_09_riesen_florian_gallay_david.cpp
# 	$(COMPILE) -c labo_09_riesen_florian_gallay_david.cpp -o $(OBJ)/labo09.o

# labo09: setup matrice.o labo09.o
# 	$(COMPILE) $(SRC)/matrice.h $(OBJ)/matrice.o $(OBJ)/labo09.o -o $(BUILDS)/labo09

# TESTS

attribute.o: setup $(SRC)/attribute.h $(SRC)/attribute.cpp
	$(COMPILE) -c $(SRC)/attribute.cpp -o $(OBJ)/attribute.o

node.o: setup $(SRC)/node.h $(SRC)/node.cpp
	$(COMPILE) -c $(SRC)/node.cpp -o $(OBJ)/node.o

test1: setup attribute.o node.o $(TESTS)/test1.cpp
	$(COMPILE) $(SRC)/attribute.h $(OBJ)/attribute.o $(SRC)/node.h $(OBJ)/node.o $(TESTS)/test1.cpp -o $(BUILDS)/test1

test2: setup attribute.o node.o $(TESTS)/test2.cpp
	$(COMPILE) $(SRC)/attribute.h $(OBJ)/attribute.o $(SRC)/node.h $(OBJ)/node.o $(TESTS)/test2.cpp -o $(BUILDS)/test2