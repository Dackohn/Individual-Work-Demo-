#include "lexer.h"
#include "token.h"
#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct PARSER_STRUCT {
    lexer_T* lexer;
    token_T* current_token;
} parser_T;



parser_T* init_parser(lexer_T* lexer);

void parser_eat(parser_T* parser, int token_type);


void parse_main(parser_T* parser);

ast_T* parse_function(parser_T* parser);

ast_T* parse_compound_statement(parser_T* parser);

ast_T* parse_statement(parser_T* parser);

ast_T* parse_loop(parser_T* parser);
