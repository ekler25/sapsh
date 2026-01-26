#include <iostream>
#include <classes/token.hpp>
#include <types.hpp>

void Ensure(String& CurrentToken, Vec<Token>& Tokens) {
    if (!CurrentToken.empty()) {
        Tokens.push_back(Token(CurrentToken, TokenTypes::Name));
        CurrentToken.clear();
    }
}

Vec<Token> Analize(String Data) {
    Vec<Token> Tokens;
    String CurrentToken;
    
    for (int x = 0; x < Data.size(); x++) {
        if (Data[x] == '.' && Data[x+1] == '.') { Ensure(CurrentToken, Tokens); Tokens.push_back(Token("..", TokenTypes::DoublePeriod)); x++; continue; }
        if (Data[x] == '.')                     { Ensure(CurrentToken, Tokens); Tokens.push_back(Token(".", TokenTypes::Period)); continue; }
        if (Data[x] == '/')                     { Ensure(CurrentToken, Tokens); Tokens.push_back(Token("/", TokenTypes::Slash)); continue; }
        if (Data[x] == '\\')                    { Ensure(CurrentToken, Tokens); Tokens.push_back(Token("\\", TokenTypes::InvertedSlash)); continue; }
        if (Data[x] == ' ')                     { Ensure(CurrentToken, Tokens); continue; }

        CurrentToken += Data[x];
    }

    Ensure(CurrentToken, Tokens);

    return Tokens;
}

int Execute(const Vec<Token>& Tokens) {
    for (auto& T : Tokens) {
        std::cout << "    " << T.Value << "\n";
    }
}