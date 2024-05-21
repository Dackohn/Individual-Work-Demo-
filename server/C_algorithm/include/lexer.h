#ifndef LEXER_H
#define LEXER_H

typedef struct {
    char* input;
    int pos;
    int len;
    char c;
} lexer_T;

lexer_T* init_lexer(char* input);
void lexer_advance(lexer_T* lexer);
char lexer_peek(lexer_T* lexer, int offset);
void lexer_skip_whitespace(lexer_T* lexer);
char* lexer_collect_number(lexer_T* lexer);
char* lexer_advance_with(lexer_T* lexer, char* value, int (*predicate)(int));

#endif
