#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <logger.h>


int main(int argc, char *argv[] ){

    if( argc == 3 ) {
        if(strcmp(argv[1],"-P") == 0){
            printLog(argv[2]);
        }
        else if(strcmp(argv[1],"--program" ) == 0){
            printLog(argv[2]);
        }
        else{
            printf("Unknown command or wrong argument\n");
            return 1;
        }
      
   }
   else if( argc == 2 ) {
      if(strcmp(argv[1],"-P") == 0){
            printLog(NULL);
        }
        else if(strcmp(argv[1],"--program" ) == 0){
            printLog(NULL);
        }
        else{
            printf("Unknown command or wrong argument\n");
            return 1;
        }
   }
   else if( argc > 3 ) {
      printf("Too many arguments supplied.\n");
   }
   else if(argc < 2){
      printf("Two argument expected.\n");
   }
    return 0;
}
