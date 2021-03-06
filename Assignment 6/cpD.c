/***
Joseph Vaiz-Gomez
CS 50 C Programming
02/5/2016

Assignment 6 Problem 1 D
(Otherwise known as: Chapter 10 Problem 1 D)

Description:
1. The program cp.c makes a copy of a file. It uses getc() and putc() to do
   the input and output. Write four new versions of a file copy program. Each of
   the programs should have the same functionality as cp.c.

   D. In the fourth version, use fscanf() to do the input and fprintf() to do the
      output.
***/
#include <stdio.h>
#include <stdlib.h>

int j=0;

int main( int argc, char * argv[] ){
	FILE *fpin, *fpout;

    char memBuffer[50];
    char * char_ptr;
    char_ptr=memBuffer;

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
    while ((fscanf(fpin, "%s", &char_ptr))!=EOF){
        fprintf(fpout, "%s ", &char_ptr);
		j++;
		if(j>=50){
			break;
		}
    }
    fclose(fpin);
    fclose(fpout);
	exit(1);
    return 0;
}
