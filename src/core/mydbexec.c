#include "mydbexec.h"
#include <string.h>

int query_callback(void *arg, int col_count, char **col_values, char **col_names){
    static int first_row = 1 ;  //Track if its the first row 

    if(first_row){
        // Print column headers
        for (int i = 0 ; i < col_count ; i++){
            printf("%-15s",col_names[i]);
        }
        printf("\n");
        first_row = 0;   //setting flag to false after headers row is done 
    }

    for(int i = 0 ; i < col_count ; i++){
        printf("%-15s",col_values[i] ? col_values[i]: "NULL");
    }
    printf("\n");

    return 0;
}

int mydb_exec(
    mydb_t *db,
    const char *sql,
    int (*callback)(void*, int, char**, char**),
    void *arg,
    char **errmsg
) {
    if (db == NULL || db->sqlite_db == NULL) {
        *errmsg = strdup("Database is not open");
        return -1;
    }

    // Ensure SELECT queries use query_callback
    int rc = sqlite3_exec(db->sqlite_db, sql, callback ? callback : query_callback, arg, errmsg);
    
    return rc == SQLITE_OK ? 0 : -1;
}
