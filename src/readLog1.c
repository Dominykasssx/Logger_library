#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <logger.h>


int main(int argc, char *argv[] ){
    int rc1;
    int rc =openDatabase(NULL);
    if (rc == 0){
    printf("OPENED DATABASE\n");
    }
    else{
    printf("ERROR OPENING DATABASE\n");
    }

    if( argc == 3 ) {
        if(strcmp(argv[1],"-P") == 0){
            rc1 = printLog(argv[2]);
        }
        else if(strcmp(argv[1],"--program" ) == 0){
            rc1 = printLog(argv[2]);
        }
        else{
            printf("Unknown command or wrong argument\n");
            return 1;
        }
      
   }
   else if( argc == 2 ) {
      if(strcmp(argv[1],"-P") == 0){
            rc1 = printLog(NULL);
        }
        else if(strcmp(argv[1],"--program" ) == 0){
            rc1 = printLog(NULL);
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
    if (rc1 == 1)
    {
        printf("List is empty\n");
    }
    rc =closeDatabase();
    if (rc == 0){
    printf("CLOSED DATABASE\n");
    }
    else{
    printf("ERROR CLOSING DATABASE\n");
    }

    return 0;
}
