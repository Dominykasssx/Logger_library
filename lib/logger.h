#define INFO 1
#define WARNING 2
#define ERROR 3
int saveLog(char *message, int level);
int printLog(char *programName);
int closeDatabase();
int openDatabase(char *programName);