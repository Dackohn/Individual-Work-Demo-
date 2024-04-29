#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "AST.h"
typedef struct {
    char* complexity;
} complexity_T;

complexity_T* init_complexity();

void increase_complexity(complexity_T* complexity, const char* level) ;

void interpret_ast(ast_T* ast, complexity_T* complexity);
#endif