# Proj07 Makefile
#
#

proj07: proj07.support.o \
	/user/cse320/Projects/project07.driver.o\
	/user/cse320/Projects/project07.hardware.h
				gcc -o proj07 proj07.support.o /user/cse320/Projects/project07.driver.o

support.o: proj07.support.c
				gcc -c proj07.support.c
