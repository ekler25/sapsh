#pragma once

#include <types.hpp>

enum TokenTypes {
    Name, StringLiteral, Variable, Period, DoublePeriod, Slash, InvertedSlash
};

struct Token {
    String Value;
    TokenTypes Type;

    Token(String V, TokenTypes T) : Value(V), Type(T) {}
};