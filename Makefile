# Makefile taken from https://github.com/simon-staal/Odyssey_C_Compiler/blob/master/Makefile.

LINK_TARGET = bin/c_compiler
CC = g++

# NOTE: use c++20 instead of c++17.
CPPFLAGS += -std=c++20 -W -Wall -g -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function
CPPFLAGS += -I include -I src

HPPFILES := $(shell find include/ -type f -name "*.hpp")
CPPFILES := $(shell find src/ -type f -name "*.cpp")
OBJS = $(patsubst %.cpp,%.o,$(CPPFILES))

all : $(LINK_TARGET)

$(LINK_TARGET) : src/lexer.yy.o src/parser.tab.o $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@

src/%.o: src/%.cpp $(HPPFILES)
	$(CC) $(CPPFLAGS) -c -o $@ $<

# NOTE: use bison instead of yacc here.
src/parser.tab.cpp src/parser.tab.hpp: src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp
	mkdir -p bin;

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp src/lexer.flex

makeobj:
	$(CC) $(CPPFLAGS) src/$(CPPALLTEST) -o bin/testout

lexer: src/lexer.yy.cpp

parser: src/parser.tab.cpp src/parser.tab.hpp

bin/compiler: src/c_compiler.output


.PHONY: clean
clean :
	rm -rf bin/*
	rm -rf out/*
	rm -f src/*.tab.hpp
	rm -f src/*.tab.cpp
	rm -f src/*.yy.cpp
	rm -f src/*.output
	find src/ -type f -name '*.o' -delete

# CPPFLAGS += -std=c++20 -W -Wall -g -I include
# HPPFILES = $(shell find include/ -type f -name "*.hpp")
# CPPFILES = $(shell find src/ -type f -name "*.cpp")

# CC = g++



# .PHONY: default

# default: bin/c_compiler

# src/%.o : src/%.cpp
# 	$(CC) $(CPPFLAGS) -c -o $@ $<

# src/lexer.yy.cpp : src/lexer.flex src/parser.tab.cpp
# 	flex -o src/lexer.yy.cpp src/lexer.flex

# src/parser.tab.cpp : src/parser.y
# 	bison -v -d src/parser.y -o src/parser.tab.cpp

# bin/c_compiler : src/cli.cpp src/compiler.cpp
# 	@mkdir -p bin
# 	g++ $(CPPFLAGS) -o bin/c_compiler $^

# clean :
# 	rm -rf bin/*
