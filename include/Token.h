#ifndef KESS_TOKEN_H_
#define KESS_TOKEN_H_

#include <stdlib.h>


typedef enum __TokenTypes {
    T_IDENTIFER,
    T_LPAREN,
    T_RPAREN,
    T_QUOTE,
    T_CHAR,
    T_INTEGER_LITERAL,
    T_END_STATEMENT,
    T_NEWLINE,
    T_PLUS,
    T_MINUS,
    T_MUL,
    T_DIV,
    T___EOF,
} tokentype_t;


typedef enum __TokIdentifiers {
    T_OUT,
} identifier_t;


typedef struct __Token {
    tokentype_t type;
    int value;
    char* string;
    char character;
    unsigned int lineNumber;
    unsigned short int builtIn;
} token_t;


typedef struct __TokenList {
    token_t* tokens;
    size_t size;
    unsigned short int begin;

} tokenlist_t;


void init_tokenlist(tokenlist_t* tokenlist, size_t size);
void destroy_tokenlist(tokenlist_t* tokenlist);
void tokenlist_add(token_t token, tokenlist_t* tokenlist);
token_t create_token(tokentype_t type, int value, char* string, char character, unsigned int lineNum, unsigned short int builtIn);

#endif
