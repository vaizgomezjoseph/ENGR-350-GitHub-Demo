/***
Joseph Vaiz-Gomez
CS 50 C Programming
02/5/2016

Assignment 6 Problem 1 B
(Otherwise known as: Chapter 10 Problem 1 B)

Description:
1. The program cp.c makes a copy of a file. It uses getc() and putc() to do
   the input and output. Write four new versions of a file copy program. Each of
   the programs should have the same functionality as cp.c.

   B. In the second version, use fgets() to do the input and fputs() to do the
      output.
***/
#include <stdio.h>
#include <stdlib.h>
/***The program is designed to be invoked with the command:

	cpB oldfile newfile
	
***/
int main( int argc, char * argv[] ){
	FILE *fpin, *fpout;
    char iochar[600];

    if( argc!=3 ){
        printf( "Usage: cp oldfile newfile\n");
        exit(1);
    }

    if (( fpin = fopen(argv[1], "r"))== NULL){

        printf("Can't open input file.\n");
        exit(1);
    }

    if(( fpout=fopen(argv[2], "w"))== NULL){

        printf("Can't open output file.\n");
        exit(1);
    }
    while ((fgets(iochar, 600, fpin)) != EOF){
        fputs(iochar, fpout);
		exit(1);
	}
    fclose(fpin);
    fclose(fpout);
    return 0;
}
