#include "mydb.h"
#include <string.h>

// Function to open a db connection 
#include "mydb.h"
#include <string.h>

int mydb_open(const char *filename, mydb_t **db) {
    *db = (mydb_t *)malloc(sizeof(mydb_t));
    if (*db == NULL) {
        return -1;  // Memory allocation failed
    }

    (*db)->filename = strdup(filename);
    if ((*db)->filename == NULL) {
        free(*db);
        return -1;
    }

    // Open SQLite database
    if (sqlite3_open(filename, &((*db)->sqlite_db)) != SQLITE_OK) {
        free((*db)->filename);
        free(*db);
        return -1;  // SQLite failed to open
    }

    return 0;  // Success
}


int mydb_close(mydb_t *db) {
    if (db == NULL) {
        return -1;
    }

    // Close SQLite connection
    if (db->sqlite_db != NULL) {
        sqlite3_close(db->sqlite_db);
    }

    free(db->filename);
    free(db);

    return 0;
}
