#include "../include/Lexer.h"


void lexer_init(lexer_t* lexer, tokenlist_t* tokens) {
    lexer -> lineNum = 1;
    lexer -> pos = 0;
    lexer -> tokenTray = tokens;
    lexer -> lineNum = 1;
}


void tokenize(lexer_t* lexer, unsigned int lineNum) {
    char lexicalBuffer[256];
    lexer -> lineNum = lineNum;

    for (int i = 0; i < strlen(lexer -> source); ++i) {
        switch (lexer -> source[i]) {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                tokenlist_add(create_token(T_CHAR, 0, lexer -> source, lexer -> source[i], lexer -> lineNum, 0), lexer -> tokenTray);
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                tokenlist_add(create_token(T_INTEGER_LITERAL, 0, NULL, lexer -> source[i], lexer -> lineNum, 0), lexer -> tokenTray);
                break;
            case ';':
                tokenlist_add(create_token(T_END_STATEMENT, 0, NULL, lexer -> source[i], lexer -> lineNum, 0), lexer -> tokenTray);
                break;
        }
    }

    if (strcmp(lexer -> source, "___EOF___") == 0) {
        tokenlist_add(create_token(T___EOF, 0, NULL, '\0', lexer -> lineNum, 0), lexer -> tokenTray);
    }
}
