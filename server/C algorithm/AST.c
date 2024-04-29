#include "include/AST.h"
#include <stdlib.h>

ast_T* init_ast(AST_NODE_TYPE type) {
    ast_T* ast = calloc(1, sizeof(struct AST_STRUCT));
    ast->type = type;
    ast->children = NULL;
    ast->children_size = 0;
    if (type == AST_FOR_LOOP) {
        ast->data.loop = calloc(1, sizeof(ast_for_loop_T));
    } else {
        ast->data.value = NULL;
    }
    return ast;
}