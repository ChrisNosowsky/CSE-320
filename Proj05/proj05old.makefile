# Make for Project 5
#
# To make Project 5 executable

proj05:	proj05.driver.o proj05.support.o
				gcc proj05.driver.o proj05.support.o -o proj05

proj05.driver.o:	proj05.driver.c
				gcc -Wall -c proj05.driver.c

proj05.support.o:	proj05.support.c
				gcc -Wall -c proj05.support.c
