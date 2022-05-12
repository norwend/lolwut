#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "token.hh"
// TODO: rewrite with iterators

std::vector<Token> tokenize(const std::string& text) {
    std::vector<Token> found;
    std::string buf;
    for (int i = 0; i < text.size(); ++i) {
	const char c = text[i];
	if (std::isalpha(c)) {
	    char currc = c;
	    while (std::isalpha(currc)) {
		buf.push_back(currc);
		currc = text[++i];
	    }
	    found.push_back(Token(TokenType::WORD, buf));
	    buf = "";
	}

	else if (c == '=') {
	    found.push_back(Token(TokenType::ASSIGN, "=")); 
	}

	else if (c == '\"' or c == '\'') {
	    char currc = text[++i];
	    while (currc != '\"' and currc != '\'') {
	        buf.push_back(currc);
		currc = text[++i];
	    }

	    found.push_back(Token(TokenType::STRING, buf));
	    buf = "";
	}

	else if (std::isdigit(c)) {
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
	    buf = "";
	}
    }
    return found;
}
