/**
 * iclc - Interactive Command Line Calculator
 *
 * lexer.h
 *
 * iclc is a simple, interactive, command line calculator. It
 * employs and thereby demonstrates basic parsing technique. 
 *
 * Beware, it leaks like a strainer and probably has more bugs
 * than Starship Troopers.
 *
 *
 * Copyright 2012 Patrick Haas (@patmanteau)
 *
 * Released under the MIT and GPL licenses.
 *
 * ------------------------------------------------
 *  author:  Patrick Haas
 *  version: 1.0.1
 *  url:     https://github.com/p7haas/iclc
 *  source:  https://github.com/p7haas/iclc
 */                                                   

#ifndef _LEXER_H_
#define _LEXER_H_

#include "main.h"

enum lex_token_t {
    TOK_EOF = -1,
    TOK_NUM = -2,
    TOK_CHAR = -3,

    TOK_PAREN_OPEN = -101,
    TOK_PAREN_CLOSE = -102,

    TOK_NOP = -255,
};

struct _LEX_CONTEXT {
    // pointer to first input character for free()'ing
    char *__input;
    char *_end_of_input;
    char *input;

    double last_token_double;
    char last_token_char;
};

typedef struct _LEX_CONTEXT lex_context;

lex_context *lex_open(const char *input);
void lex_close(lex_context *ctx);
int lex_get_token(lex_context *ctx);

#endif 



