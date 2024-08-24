#include "syntax/analyzer.hpp"

#include "syntax/cfg/definition.hpp"

namespace icy {

namespace syntax {

auto analyzer::scan(const std::vector<lexical::lexeme>& _seq) -> void {
    auto* const _e = cfg::_syntax_factory->get("EXPR");
    node _root(_e);
    auto _result = _e->operator()(&_root, _seq.cbegin(), _seq.cend(), true);
    auto _s = _root.syntax()->label();
    print_node(&_root);
    _root.clear();
    return;
}

}

}
