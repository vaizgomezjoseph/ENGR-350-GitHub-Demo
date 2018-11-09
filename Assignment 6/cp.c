/***
Joseph Vaiz-Gomez
CS 50 C Programming
02/5/2016

Assignment 6 Problem 1 cp.c
(Otherwise known as: Chapter 10 Problem 1)

Description:
1. The program cp.c makes a copy of a file. It uses getc() and putc() to do
   the input and output. Write four new versions of a file copy program. Each of
   the programs should have the same functionality as cp.c.

   A. In the first version, use fgetc() to do the input and fputc() to do the
      output.

   B. In the second version, use fgets() to do the input and fputs() to do the
      output.

   C. In the third version, use fread() to do the input and fwrite() to do the
      output.

   D. In the fourth version, use fscanf() to do the input and fprintf() to do the
      output.

   E. Compare the sizes of the object code from all five versions of the file copy
      programs. If facilities for testing execution efficiency are available on your
      system, test the efficiency of each version. Report your findings.
***/
#include <stdio.h>
#include <stdlib.h>

/***The program is designed to be invoked with the command:

	cp oldfile newfile

***/

int main( int argc, char * argv[] ){
	FILE *fpin;
	FILE *fpout;
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
    while ((iochar = getc(fpin)) != EOF)
        putc(iochar, fpout);

    fclose(fpin);
    fclose(fpout);
    return 0;
}
