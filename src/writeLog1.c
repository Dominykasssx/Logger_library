#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <logger.h>
#include <stdlib.h>

int main(int argc, char *argv[] )
{

    while(1){
    int rc;
    rc =openDatabase(argv[0]);
    if (rc == 0){
    printf("OPENED DATABASE\n");
    }
    else{
    printf("ERROR OPENING DATABASE\n");
    exit(1);
    }

    int rc1  = saveLog("Message from program", 1);
    if(rc1 == 1){
    printf("level is incorrect, should be 1,2 or 3\n");
    }
    else{
        printf("Message logged\n");
    }
    sleep(10);

    rc =closeDatabase();
    if (rc == 0){
    printf("CLOSED DATABASE\n");
    }
    else{
    printf("ERROR CLOSING DATABASE\n");
    exit(1);
    }
    }
    
    return 0;
}