#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "token.hh"
// TODO: rewrite with iterators

std::vector<Token> tokenize(const std::string& text) {
    std::vector<Token> found;
    for (int i = 0; i < text.size(); ++i) {
	const char c = text[i];
	if (std::isalpha(c)) {
	    std::string buf;
	    char currc = c;
	    while (std::isalpha(currc)) {
		buf.push_back(currc);
		currc = text[++i];
	    }
	    found.push_back(Token(TokenType::WORD, buf));
	}

	else if (c == '=') {
	    found.push_back(Token(TokenType::ASSIGN, "=")); 
	}

	else if (c == '\"' or c == '\'') {
	    std::string buf;
	    char currc = text[++i];
	    while (currc != '\"' and currc != '\'') {
	        buf.push_back(currc);
		currc = text[++i];
	    }

	    found.push_back(Token(TokenType::STRING, buf));
	}

	else if (std::isdigit(c)) {
	    std::string buf;
	    char currc = c;
	    TokenType type = INTEGER;
	    while (std::isdigit(currc)) {
		buf.push_back(currc);
		currc = text[++i];
	    }
	    if (currc == '.') {
		type = FLOAT;
		buf.push_back('.');
		currc = text[++i];
		while (std::isdigit(currc)) {
		    buf.push_back(currc);
		    currc = text[++i];
		}
	    }

	    found.push_back(Token(type, buf));
	}
    }
    return found;
}
