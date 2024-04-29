// AST.h
#ifndef AST_H
#define AST_H

typedef enum {
    AST_FOR_LOOP,
    AST_FUNCTION_CALL,
    AST_COMPOUND
} AST_NODE_TYPE;

typedef struct AST_STRUCT {
    AST_NODE_TYPE type;
    struct AST_STRUCT** children;
    size_t children_size;
    union {
        char* value;
        struct {
            char* init;
            char* condition;
            char* increment;
        } loop;
    } data;
} ast_T;

ast_T* init_ast(AST_NODE_TYPE type);

#endif // AST_H
