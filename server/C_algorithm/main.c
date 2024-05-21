#include "include/lexer.h"
#include "include/parser.h"
#include "include/read.h"
#include <stdio.h>

int main() {
    char* source_code = get_file_contents("./received_contents.txt");
    lexer_T* lexer = init_lexer(source_code);
    parser_T* parser = init_parser(lexer);
    int depth = parse_for_loops(parser);
    printf("%d",depth);
    return depth;
}
 