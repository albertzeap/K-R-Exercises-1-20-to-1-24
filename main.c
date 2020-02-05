#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_STOP 10
#define MAX_TAB_STOP 60

int main(int argc, const char * argv[]) {
    if (argc != 3 && argc != 4 ){
        fprintf(stderr, "Usage : ./detab inputfile(outputfile tabstops (optional)\n");
        exit(1);
    }

   

    FILE * fin = fopen(argv[1], "r");
    FILE * fout = fopen(argv[2], "w");
    if (fin == NULL || fout == NULL){
        fprintf(stderr,"Usage: ./detab inputfile outputfile\n" );
        exit(1);
    }
   
    int c;
    char maxspaces[MAX_TAB_STOP + 1];
    char spaces[MAX_TAB_STOP +1];
    memset(maxspaces,' ', sizeof(maxspaces));


    
    int amount_written;
    while ((c = fgetc(fin)) != EOF) {
        if (c != ' '){
            fputc ( c ,fout);
            ++amount_written;
        }
        else {
            int bytes_to_tab = TAB_STOP - (amount_written % TAB_STOP);
            fputc('\t', fout);
            strncpy(spaces, maxspaces, bytes_to_tab);
            spaces[bytes_to_tab] = '\0';
            fputs(spaces, fout);
            amount_written += strlen(spaces);
            
        }
        


    }

    
    
   

 

     fclose (fin);
     fclose(fout);
     return 0;
}