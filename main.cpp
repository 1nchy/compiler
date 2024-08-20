#include "lexical/analyzer.hpp"

#include "signal_stack.hpp"

#include "argument_parser.hpp"

int main(int _argc, char* _argv[]) {
    icy::signal_stack _s;
    icy::argument_parser _p;
    icy::lexical::analyzer _a;
    const std::string _line = "const x = 1.2 + (3 * 4)";
    _a.scan(_line.cbegin(), _line.cend());
    const auto& _seq = _a.lexeme_sequence();
    return 0;
}