#ifndef MYDBEXEC_H
#define MYDBEXEC_H

#include <stdio.h>
#include <stdlib.h>
#include "mydb.h"

int mydb_exec(
    mydb_t *db,                                  /* An open database */
    const char *sql,                           /* SQL to be evaluated */
    int (*callback)(void*,int,char**,char**),  /* Callback function */
    void *,                                    /* 1st argument to callback */
    char **errmsg                              /* Error msg written here */
  );



#endif // MYDBEXEC_H