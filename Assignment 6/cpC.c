/***
Joseph Vaiz-Gomez
CS 50 C Programming
02/5/2016

Assignment 6 Problem 1 C
(Otherwise known as: Chapter 10 Problem 1 C)

Description:
1. The program cp.c makes a copy of a file. It uses getc() and putc() to do
   the input and output. Write four new versions of a file copy program. Each of
   the programs should have the same functionality as cp.c.

   C. In the third version, use fread() to do the input and fwrite() to do the
      output.
***/
#include <stdio.h>
#include <stdlib.h>
/***The program is designed to be invoked with the command:

	cpC oldfile newfile

***/

int i;
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
    //printf("Gotten this far. %d\n", fread(&memBuffer,sizeof(char),50, fpin));
    //fflush(stdin);
    i=fread(&char_ptr,sizeof(char),(50), fpin);
    while (i){
        fwrite(&char_ptr,sizeof(char),(i), fpout);
		exit(1);
	}

    fclose(fpin);
    fclose(fpout);
    return 0;
}
