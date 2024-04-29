#include <stdio.h>
#include "lexer.c"
#include "read.c"
#include "token.c"
#include "interpreter.c"

int main() {
    lexer_T* lexer = init_lexer(get_file_contents("file.txt"));
    parser_T* parser = init_parser(lexer);
    ast_T* root = parse_main(parser);

    complexity_T* complexity = init_complexity();
    interpret_ast(root, complexity);

    printf("Computed complexity: %s\n", complexity->complexity);
    return 0;
}