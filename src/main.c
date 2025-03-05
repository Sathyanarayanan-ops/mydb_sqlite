#include "core/mydb.h"
#include "core/mydbexec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024  // Max SQL command length

void start_repl(mydb_t *db) {
    char input[MAX_INPUT_SIZE];
    char *errmsg = NULL;

    printf("Welcome to mydb! Type SQL commands or '.exit' to quit.\n");

    while (1) {
        printf("mydb> ");  // REPL prompt
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            printf("\nExiting...\n");
            break;
        }

        // Remove newline from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, ".exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Execute the command
        mydb_exec(db, input, NULL, NULL, &errmsg);

        if (errmsg) {
            printf("SQL Error: %s\n", errmsg);
            free(errmsg);  // Free allocated error message
            errmsg = NULL;
        }
    }
}

int main() {
    mydb_t *db;

    // Open database
    if (mydb_open("test.db", &db) != 0) {
        printf("Failed to open database.\n");
        return 1;
    }

    // Start the interactive REPL
    start_repl(db);

    // Close database
    mydb_close(db);

    return 0;
}
