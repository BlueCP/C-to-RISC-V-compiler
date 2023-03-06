CPPFLAGS += -std=c++20 -W -Wall -g -I include
HPPFILES = $(shell find include/ -type f -name "*.hpp")
CPPFILES = $(shell find src/ -type f -name "*.hpp")

CC = g++



.PHONY: default

default: bin/c_compiler

src/%.o : src/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

src/lexer.yy.c : src/lexer.flex src/parser.tab.cpp
	flex -o src/lexer.yy.c src/lexer.flex

src/parser.tab.cpp : src/parser.y
	yacc -v src/parser.y -o src/parser.tab.cpp

bin/c_compiler : src/cli.cpp src/compiler.cpp
	@mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^

clean :
	rm -rf bin/*
