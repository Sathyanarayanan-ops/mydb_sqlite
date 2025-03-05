// #ifndef MYDB_H
// #define MYDB_H

// #include <stdio.h>
// #include <stdlib.h>

// // Creating a db connection handle struct
// typedef struct mydb{
//     FILE *db_file;  // File pointer for database storage
//     char *filename; // Stores the database filename 
// } mydb_t;

// // mydb_t is actually a shorthand for struct mydb


// int mydb_open(
//     const char *filename,
//     mydb_t **db
// );

// int mydb_close(
//     mydb_t *db
// );

// #endif // MYDB_H


#ifndef MYDB_H
#define MYDB_H

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>  // Include SQLite

// Database Connection Handle
typedef struct mydb {
    sqlite3 *sqlite_db;  // SQLite database connection
    char *filename;      // Stores the database filename
} mydb_t;

// Function to open a database connection
int mydb_open(const char *filename, mydb_t **db);

// Function to close a database connection
int mydb_close(mydb_t *db);

#endif // MYDB_H
