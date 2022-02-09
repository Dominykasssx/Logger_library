#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <logger.h>
#include <stdlib.h>

int main(int argc, char *argv[] )
{
    while(1){
    saveLog(argv[0],"Message from program", 1);
    sleep(10);
    }
    return 0;
}