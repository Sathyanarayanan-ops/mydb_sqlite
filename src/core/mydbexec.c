#include "mydbexec.h"
#include <string.h>

int mydb_exec(
    mydb_t *db,
    const char *sql,
    int (*callback)(void*, int , char**, char**),
    void *arg,                                   
    char **errmsg
){
    if(db == NULL || db->db_file == NULL){
        *errmsg = strdup("Database is not open");
        return -1;
    }
    printf("Executing SQL: %s\n",sql);

    // For now simulate execution by checking the query type 
    if (strncmp(sql, "SELECT", 6) == 0) {
        printf("Simulated: Querying data...\n");
        return 0;  // Indicating success
    } else if (strncmp(sql, "INSERT", 6) == 0) {
        printf("Simulated: Inserting data...\n");
        return 0;
    } else if (strncmp(sql, "CREATE", 6) == 0) {
        printf("Simulated: Creating table...\n");
        return 0;
    } else {
        *errmsg = strdup("Unsupported SQL command");
        return -1;  // Error
    }

    return 0;
}