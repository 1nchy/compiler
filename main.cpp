#include "lexical/analyzer.hpp"
#include "syntax/analyzer.hpp"
#include "syntax/cfg/definition.hpp"

#include "signal_stack.hpp"

#include "argument_parser.hpp"

int main(int _argc, char* _argv[]) {
    icy::signal_stack _s;
    icy::argument_parser _p;
    icy::lexical::analyzer _la;
    const std::string _line = "1.2";
    _la.scan(_line.cbegin(), _line.cend());
    const auto& _seq = _la.lexeme_sequence();
    icy::syntax::cfg::initialize();
    icy::syntax::analyzer _sa;
    _sa.scan(_seq);
    return 0;
}