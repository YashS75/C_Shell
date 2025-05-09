/* File: src/shell.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include "parser.h"
#include "executor.h"

#define MAX_LINE 1024

void shell_loop() {
    char line[MAX_LINE];
    char **args;
    int status = 1;

    while (status) {
        printf("mysh> ");
        if (!fgets(line, MAX_LINE, stdin)) break;
        args = parse_line(line);
        if (args[0] != NULL) {
            status = execute_command(args);
        }
        free(args);
    }
}

