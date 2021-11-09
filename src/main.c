#include <stdio.h>
#include "../include/Lexer.h"
#include "../include/Parser.h"


int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1], "r");

    char lineBuffer[500];

    tokenlist_t tokenlist;
    init_tokenlist(&tokenlist, 4);

    lexer_t lexer;
    lexer_init(&lexer, &tokenlist);

    unsigned int lineNum = 1;

    while (fgets(lineBuffer, 500, fp)) {
        lexer.source = lineBuffer;
        tokenize(&lexer, lineNum);
        ++lineNum;
    }

    fclose(fp);

    parser_t parser;
    init_parser(&parser, &tokenlist);
    parse(&parser);
    destroy_tokenlist(&tokenlist);
}
