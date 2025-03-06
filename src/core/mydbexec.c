#include "mydbexec.h"
#include <string.h>

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

    // Execute SQL using SQLite
    int rc = sqlite3_exec(db->sqlite_db, sql, callback, arg, errmsg);
    if (rc != SQLITE_OK) {
        return -1;  // SQL execution failed
    }

    return 0;  // Success
}
