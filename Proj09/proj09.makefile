# Project 09 Executable
#
# Execute the driver and support
proj09:	proj09.driver.o	proj09.support.o
				gcc proj09.driver.o	proj09.support.o	-o proj09

proj09.support.o:	proj09.support.s
				gcc -march=native -c proj09.support.s

proj09.driver.o:	proj09.driver.c
				gcc -Wall -c proj09.driver.c
