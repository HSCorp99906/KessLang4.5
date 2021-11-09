#ifndef KESS_LEXER_H_
#define KESS_LEXER_H_

#include <string.h>
#include <stdio.h>
#include "Token.h"


typedef struct Lexer {
    char* source;
    char currentChar;
    unsigned int pos;
    tokenlist_t* tokenTray;
    unsigned int lineNum;

} lexer_t;


void tokenize(lexer_t* lexer, unsigned int lineNum);
void lexer_init(lexer_t* lexer, tokenlist_t* tokens);


#endif
