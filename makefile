CC=gcc
all: compile
compile:
	${CC} -g main.c staticSet.c dynamicSet.c specOps.c
