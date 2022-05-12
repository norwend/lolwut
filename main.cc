#include <sstream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

#include "lexer.hh"

int main(int argc, char** argv) {
    if (argc == 1) {
	throw std::runtime_error("No arguments provided!");
    }
    std::fstream f(argv[1]);
    std::stringstream s;
    s << f.rdbuf();
    std::string str = s.str();
    auto a = tokenize(str);
    for (const auto& t: a) {
	std::cout << t << std::endl;
    }
    return 0;
}
