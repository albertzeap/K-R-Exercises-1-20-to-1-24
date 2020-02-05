#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 //current input line


int main(int argc, const char * argv[]) {
    if (argc != 2 && argc != 3 ){
        fprintf(stderr, "Usage : ./detab inputfile(outputfile\n");
        exit(1);
    }

   

    FILE * fin = fopen(argv[1], "r");
    FILE * fout = fopen(argv[2], "w");
    if (fin == NULL || fout == NULL){
        fprintf(stderr,"Usage: ./detab inputfile outputfile\n" );
        exit(1);
    }
   
    int c;
    const int folding_length = 50;
    char line[MAXLINE + 1 ];
    


    
    int fold_count = 0;
    while ((c = fgetc(fin)) != EOF) {
        if (fold_count < folding_length) {
            fputc(c, fout);
            ++fold_count;
        }
        else {
            fold_count = 0;
            fputc('\n', fout);
    
        }


    }

    
    
   

 

     fclose (fin);
     fclose(fout);
     return 0;
}