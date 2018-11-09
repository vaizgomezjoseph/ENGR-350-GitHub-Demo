/***
Joseph Vaiz-Gomez
CS 50 C Programming
02/5/2016

Assignment 6 Problem 1 A
(Otherwise known as: Chapter 10 Problem 1 A)

Description:
1. The program cp.c makes a copy of a file. It uses getc() and putc() to do
   the input and output. Write four new versions of a file copy program. Each of
   the programs should have the same functionality as cp.c.

   A. In the first version, use fgetc() to do the input and fputc() to do the
      output.
***/
#include <stdio.h>
#include <stdlib.h>
/***The program is designed to be invoked with the command:

	cpA oldfile newfile
	
***/
int main(int argc, char * argv[]){
    FILE *fpin, *fpout;
    int iochar;

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
    while ((iochar = fgetc(fpin)) != EOF)
        fputc(iochar, fpout);

    fclose(fpin);
    fclose(fpout);
    return 0;
}
