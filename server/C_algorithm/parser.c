#include "include/parser.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

parser_T* init_parser(lexer_T* lexer) {
    parser_T* parser = calloc(1, sizeof(parser_T));
    parser->lexer = lexer;
    return parser;
}

int parse_for_loops(parser_T* parser) {
    int depth = 0;
    lexer_skip_whitespace(parser->lexer);

    while (parser->lexer->c != '\0') {
        if (parser->lexer->c == 'f') {
            char* potential_for = lexer_advance_with(parser->lexer, calloc(1, sizeof(char)), isalpha);
            if (strcmp(potential_for, "for") == 0) {
                depth++;
            }
            free(potential_for);
        }
        lexer_advance(parser->lexer);
        lexer_skip_whitespace(parser->lexer);
    }

    return depth;
}
