#include "core/mydb.h"
#include "core/mydbexec.h"
#include <stdio.h>

int main() {
    mydb_t *db;
    char *errmsg = NULL;

    // Open database
    if (mydb_open("test.db", &db) == 0) {
        printf("Database opened successfully: %s\n", db->filename);
    } else {
        printf("Failed to open database.\n");
        return 1;
    }

    // Execute SQL queries
    mydb_exec(db, "CREATE TABLE users (id INT, name TEXT);", NULL, NULL, &errmsg);
    mydb_exec(db, "INSERT INTO users VALUES (1, 'Alice');", NULL, NULL, &errmsg);
    mydb_exec(db, "SELECT * FROM users;", NULL, NULL, &errmsg);

    if (errmsg) {
        printf("SQL Error: %s\n", errmsg);
    }

    // Close database
    if (mydb_close(db) == 0) {
        printf("Database closed successfully.\n");
    } else {
        printf("Failed to close database.\n");
    }

    return 0;
}
