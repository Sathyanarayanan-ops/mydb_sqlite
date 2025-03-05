#include "core/mydb.h"
#include "core/mydbexec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Callback to print SELECT results
static int print_results(void *unused, int num_columns, char **column_values, char **column_names) {
    (void)unused;
    for (int i = 0; i < num_columns; i++) {
        printf("%-15s", column_names[i]);
    }
    printf("\n");
    for (int i = 0; i < num_columns; i++) {
        printf("%-15s", column_values[i] ? column_values[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void start_repl(mydb_t *db) {
    char input[MAX_INPUT_SIZE];
    char *errmsg = NULL;

    while (1) {
        printf("mydb> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, ".exit") == 0) break;

        // Use callback ONLY for SELECT-like queries
        int (*callback)(void*,int,char**,char**) = NULL;
        if (strncasecmp(input, "SELECT", 6) == 0) {
            callback = print_results; // Use your print_results callback
        }

        if (mydb_exec(db, input, callback, NULL, &errmsg) != 0) {
            printf("Error: %s\n", errmsg);
            sqlite3_free(errmsg);
        }
    }
}

int main() {
    mydb_t *db;

    if (mydb_open("test.db", &db) != 0) {
        printf("Failed to open database.\n");
        return 1;
    }

    start_repl(db);
    mydb_close(db);

    return 0;
}