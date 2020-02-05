#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1         /* in a comment */
#define OUT 0        /* out a comment */


int main(int argc, const char * argv[]) {
    if (argc != 2 && argc != 3 ){
        fprintf(stderr, "Usage : ./detab inputfile outputfile \n");
        exit(1);
    }

    FILE * fin = fopen(argv[1], "r"); //read from the first file
    FILE * fout = fopen(argv[2], "w"); //read from the second file

    if (fin == NULL || fout == NULL){
        fprintf(stderr,"Usage: ./detab inputfile outputfile\n" );
        exit(1);
    }





    int c, prev_c, pprev_c;
    int state = OUT;



    while ((c = fgetc(fin)) != EOF) {
        if ((c == '/' && prev_c == '/') || (c == '*' && prev_c == '/')){
          state = IN;
        }
        else if (c != '/' && (prev_c == '/' && pprev_c == '*')){
          state = OUT;
        }
        else if(state != IN) {
          fputc(c,fout);
        }
        pprev_c = prev_c;
        prev_c = c;

        
      }






     fclose (fin);
     fclose(fout);
     return 0;
}
