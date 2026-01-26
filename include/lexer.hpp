#pragma once

#include <classes/token.hpp>
#include <types.hpp>

Vec<Token> Analize(String Data);
int Execute(const Vec<Token>& Tokens);