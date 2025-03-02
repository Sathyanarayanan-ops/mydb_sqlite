#include <stdio.h>
#include "core/mydb.h" 


int main() {
    mydb_t *db;

    if (mydb_open("test.db",&db)==0) {
        printf("Database opened successfully : %s\n ",db->filename);
    } else {
        printf("Failed to open database.\n");
        return 1;
    }

    if (mydb_close(db) == 0) {
        printf("Database closed successfully.\n");
    } else {
        printf("Failed to close database.\n");
    }

    return 0;
}