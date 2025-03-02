#include "mydb.h"
#include <string.h>

// Function to open a db connection 
int mydb_open(const char *filename, mydb_t **db){
    // allocate memory for the db handle 
    *db = (mydb_t *)malloc(sizeof(mydb_t));
    if (*db == NULL){
        return -1; // memory allocation fail
    }

    // store the filename in the database handle 
    (*db)->filename = strdup(filename);
    if ((*db)->filename == NULL){
        free(*db);
        return -1;  //memory allocation fail
    }

    // Open the database file

    (*db)->db_file = fopen(filename , "a+");
    if ((*db)->db_file == NULL){
        free((*db)->filename);
        free(*db);
        return -1;
    }

    return 0; // success
}

int mydb_close(mydb_t *db){
    if (db == NULL){
        return -1 ;
    }

    // close the file if open 

    if(db->db_file != NULL){
        fclose(db->db_file);
    }

    free(db->filename);
    free(db);

    return 0;
}