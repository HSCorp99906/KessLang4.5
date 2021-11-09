#include "../include/Parser.h"


void init_parser(parser_t* parser, tokenlist_t* tokens) {
    parser -> tokenTray = tokens;
    parser -> currentToken = *tokens -> tokens;
    parser -> currentPos = 0;
}


void advance(parser_t* parser) {
    if (parser -> currentPos < parser -> tokenTray -> size) {
        ++parser -> currentPos;
        parser -> currentToken = parser -> tokenTray -> tokens[parser -> currentPos];
     }
}


void parse(parser_t* parser) {
    typedef unsigned short int bool_t;

    bool_t semicolon = 0;
    int lastIndex = 0;
    bool_t look_for_semi_colon = 1;
    bool_t start_advancing = 0;

    while (1) {
        if (look_for_semi_colon) {
            for (int i = lastIndex; i < parser -> tokenTray -> size; ++i) {
                if (parser -> tokenTray -> tokens[i].type == T_END_STATEMENT) {
                    semicolon = 1;
                    lastIndex = i + 1;
                    break;
                } else if (parser -> tokenTray -> tokens[i].type == T___EOF) {
                    start_advancing = 1;
                    break;
                }
            }
        }

        if (!(semicolon)) {
            printf("ERROR: Missing semicolon on line %d.\n", parser -> tokenTray -> tokens[lastIndex].lineNumber);
            break;
        }

        if (parser -> currentToken.type == T___EOF) {
            break;
        }

        if (start_advancing) {
            advance(parser);
        }
    }
}
