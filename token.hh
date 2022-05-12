#pragma once
#include <string>
#include <vector>
#include <iostream>

enum TokenType {STRING, INTEGER, WORD, FLOAT, ASSIGN};

class Token {
public:
    Token() = default;
    Token(const TokenType& t, const std::string& c): type_(t), contents_(c) {}
    Token(const TokenType& t, const char& c): type_(t), contents_(std::to_string(c)) {}
    const std::string get_contents() const { return contents_; }
    const TokenType get_type() const { return type_; }

    
private:
    TokenType type_;
    std::string contents_;
};

std::ostream& operator<<(std::ostream& os, const Token& t) {
    os << "Contents: " << t.get_contents() << "\nType: ";
    switch(t.get_type()) {
    case STRING:
	os << "String";
	break;
    case INTEGER:
	os << "Integer";
	break;
    case ASSIGN:
	os << "Assign";
	break;
    case WORD:
	os << "Word/Keyword";
	break;
    case FLOAT:
	os << "Float";
	break;
    }
    return os;
}
