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

    int tab_interval = argc == 4 ? atoi(argv[3]) : TAB_STOP;
    if (tab_interval > 60) {
        fprintf(stderr, "tabstops must be <= 60 characters\n");
        exit(2);
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

    
    int bytes_written = 0;
    while ((c = fgetc(fin) != EOF)) {
         if (c != '\t'){
            fputc(c, fout) ;
            ++bytes_written;
        }
        else {
            int bytes_to_tab = TAB_STOP - (bytes_written % TAB_STOP);
            strncpy(spaces, maxspaces, bytes_to_tab);
            spaces[bytes_to_tab] = '\0';
            fputs(spaces, fout);
            bytes_written += strlen(spaces);
               
        
        }       

    }

 

     fclose (fin);
     fclose(fout);
     return 0;
}
