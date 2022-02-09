#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "logger.h"

int flag = 0;

int callback(void *a_param, int argc, char **argv, char **column){
    for (int i=1; i< argc; i++)
    printf("%s\t", argv[i]);
    printf("\n");
    flag++;
    return 0;
}

void sqlQuery(char *message){
    sqlite3 *db = NULL;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("/var/log/logger.db", &db);

    if( rc ) {
    fprintf(stderr, "Can't create database: %s\n", sqlite3_errmsg(db));
    } else {
    fprintf(stderr, "Opened database successfully\n");
    }

    rc = sqlite3_exec(db, message, callback, 0, &zErrMsg);
    free(message);
   
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Sql query executed successfully\n");
        if(flag ==0){
            fprintf(stdout, "Empty list\n");
        }
        else if(flag == -1){
            fprintf(stdout, "Log written successfully\n");
        }
    }
        sqlite3_close(db);
}


void printLog(char *programName){    
    
    char *sql = (char*) malloc(sizeof(char) * 250);
    if (programName == NULL){
        sprintf (sql,"SELECT * FROM Log");
    }
    else{
        sprintf (sql,"SELECT * FROM Log WHERE Program='%s';",programName);
    }
    sqlQuery(sql);
}

void saveLog(char *programName,char *message, int level){
     flag = -1;
     if(level < 0 || level > 3){
        printf("level is incorrect, should be 1,2 or 3\n");
         exit(1);
     }
    char *sql = (char*) malloc(sizeof(char) * 250);

    sprintf (sql,"CREATE TABLE IF NOT EXISTS Log (Id INTEGER PRIMARY KEY, Program TEXT, Message TEXT, Level INT); \
                  INSERT INTO Log (Program,Message,Level) VALUES ('%s','%s','%d');",programName,message,level);
    sqlQuery(sql);
}


