#include "include/lexer.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

lexer_T* init_lexer(char* input) {
    lexer_T* lexer = calloc(1, sizeof(lexer_T));
    lexer->input = input;
    lexer->pos = 0;
    lexer->len = strlen(input); 
    lexer->c = input[lexer->pos];
    return lexer;
}

void lexer_advance(lexer_T* lexer) {
    if (lexer->pos < lexer->len && lexer->c != '\0') {
        lexer->pos++;
        lexer->c = lexer->pos < lexer->len ? lexer->input[lexer->pos] : '\0';
    }
}

char lexer_peek(lexer_T* lexer, int offset) {
    return lexer->pos + offset < lexer->len ? lexer->input[lexer->pos + offset] : '\0';
}

void lexer_skip_whitespace(lexer_T* lexer) {
    while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n') lexer_advance(lexer);
}

char* lexer_collect_number(lexer_T* lexer) {
    return lexer_advance_with(lexer, calloc(1, sizeof(char)), isdigit);
}

char* lexer_advance_with(lexer_T* lexer, char* value, int (*predicate)(int)) {
    while (lexer->c != '\0' && predicate((int)lexer->c)) {
        char str[2] = {lexer->c, '\0'};
        strcat(value, str);
        lexer_advance(lexer);
    }
    return value;
}
