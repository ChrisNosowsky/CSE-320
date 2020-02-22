#	Execution file for Project 10
#
#

proj10:	proj10.driver.o proj10.support.o
				gcc proj10.driver.o proj10.support.o -o proj10

proj10.driver.o:	proj10.driver.c
				gcc -Wall -c proj10.driver.c

proj10.support.o:	proj10.support.s
				gcc -Wall -c proj10.support.s
