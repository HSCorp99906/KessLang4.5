#ifndef KESS_PARSER_H_
#define KESS_PARSER_H_

#include "Token.h"
#include <stdio.h>


typedef struct Parser {
    tokenlist_t* tokenTray;
    token_t currentToken;
    unsigned int currentPos;
} parser_t;


void init_parser(parser_t* parser, tokenlist_t* tokens);
void parse(parser_t* parser);


#endif
