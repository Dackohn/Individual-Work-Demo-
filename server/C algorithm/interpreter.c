#include "include/interpreter.h"
#include "include/AST.h"
#include "include/parser.h"


complexity_T* init_complexity() {
    complexity_T* complexity = calloc(1, sizeof(struct complexity_T));
    complexity->complexity = strdup("O(1)"); // Start with constant complexity
    return complexity;
}

void increase_complexity(complexity_T* complexity, const char* level) {
    free(complexity->complexity);
    complexity->complexity = strdup(level);
}

void interpret_ast(ast_T* ast, complexity_T* complexity) {
    if (ast == NULL) return;

    switch (ast->type) {
        case AST_FOR_LOOP:
            if (strstr(ast->data.loop->increment, "++") != NULL || strstr(ast->data.loop->increment, "--") != NULL) {
                increase_complexity(complexity, "O(n)");
            } else if (strstr(ast->data.loop->increment, "*=") != NULL || strstr(ast->data.loop->increment, "/=") != NULL) {
                increase_complexity(complexity, "O(log n)");
            }
            for (size_t i = 0; i < ast->children_size; i++) {
                interpret_ast(ast->children[i], complexity);
            }
            break;
        case AST_FUNCTION_CALL:
            printf("Function call: %s\n", ast->data.value);
            break;
        case AST_COMPOUND:
            for (size_t i = 0; i < ast->children_size; i++) {
                interpret_ast(ast->children[i], complexity);
            }
            break;
    }
}

