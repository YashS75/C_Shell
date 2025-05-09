/* File: src/parser.c */
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define MAX_TOKENS 64
#define DELIM " \\t\n"

char **parse_line(char *line) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char*));
    char *token;
    int position = 0;

    token = strtok(line, DELIM);
    while (token != NULL) {
        tokens[position++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}
