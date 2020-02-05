#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 2

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

   int c,state = OUT,
       opening = 1, closing = -1, balance = 0;

   while ((c = fgetc(fin)) != EOF) {
     if ((c == '(') || (c == '[') || (c == '{') ||(c == '"')){
       state = IN;
       fputc(c,fout);
       balance += opening;

       if ( state == IN){

         if ((c  != ')') || (c != ']') || (c != '}') ||(c != '"')){
           fputc(')', fout);
           balance += closing;
         }
       }
   }
   






      else {
        fputc(c,fout);
   }
 }



  return 0;
}
