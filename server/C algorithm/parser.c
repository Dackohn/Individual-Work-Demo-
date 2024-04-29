#include "lexer.h"
#include "token.h"

void parser_eat(parser_T* parser, int token_type) {
    if (parser->current_token->type == token_type) {
        parser->current_token = lexer_get_next_token(parser->lexer);
    } else {
        printf("Error: Unexpected token '%s'\n", parser->current_token->value);
        exit(1);
    }
}

char* extract_loop_part(parser_T* parser, int delimiter) {
    char* part = calloc(1, sizeof(char));
    size_t length = 0;
    size_t capacity = 1;

    while (parser->current_token->type != delimiter && parser->current_token->type != TOKEN_RPAREN) {
        size_t token_length = strlen(parser->current_token->value);
        if (length + token_length >= capacity) {
            capacity = (length + token_length) * 2;
            part = realloc(part, capacity);
        }
        strcat(part, parser->current_token->value);
        parser_advance(parser); // Needs to be implemented
    }

    if (parser->current_token->type == delimiter) {
        parser_eat(parser, delimiter); // Consume ';' or ')'
    }

    return part;
}

ast_T* parse_for_loop(parser_T* parser) {
    parser_eat(parser, TOKEN_FOR);
    parser_eat(parser, TOKEN_LPAREN);

    ast_T* loop = init_ast(AST_FOR_LOOP);
    loop->data.loop->init = extract_loop_part(parser, TOKEN_SEMI);
    loop->data.loop->condition = extract_loop_part(parser, TOKEN_SEMI);
    loop->data.loop->increment = extract_loop_part(parser, TOKEN_RPAREN);

    parser_eat(parser, TOKEN_LBRACE);

    loop->children = calloc(1, sizeof(struct AST_STRUCT*));
    loop->children_size = 1;
    loop->children[0] = parse_compound_statement(parser);

    parser_eat(parser, TOKEN_RBRACE);
    return loop;
}
