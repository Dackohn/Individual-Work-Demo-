#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct {
    lexer_T* lexer;
} parser_T;

parser_T* init_parser(lexer_T* lexer);
int parse_for_loops(parser_T* parser);

#endif
