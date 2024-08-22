#ifndef _ICY_SYNTAX_CFG_DEFINITION_HPP_
#define _ICY_SYNTAX_CFG_DEFINITION_HPP_

#include <vector>
#include <type_traits>
#include "lexical/lexeme.hpp"

#include "abstract_factory.hpp"

namespace icy {

namespace syntax {

namespace cfg {
    
using iter = std::vector<lexical::lexeme>::const_iterator;

struct virtual_syntax;
struct virtual_syntax {
    virtual iter operator()(iter, iter) = 0;
    virtual ~virtual_syntax() = default;
};

using rule_t = std::vector<std::string>;
auto* const _syntax_factory = icy::factory<virtual_syntax>::instance();
void _S_initialize_syntax_factory();

#define KEYWORD_DECL(key) \
struct keyword_##key : public virtual_syntax { \
    iter operator()(iter _b, iter _e) override { \
        if (_b == _e) return _b; \
        if (_b->token() == lexical::token_t::tk_##key) { \
            return _b + 1; \
        } \
        return _b; \
    } \
}
#define SYNTAX_DECL(syn) \
struct syntax_##syn : public virtual_syntax { \
    iter operator()(iter _b, iter _e) override { \
        if (_b == _e) return _b; \
        if (_b->token() == lexical::token_t::tk_##syn) { \
            return _b + 1; \
        } \
        return _b; \
    } \
}
#define RULED_SYNTAX_DECL(syn) \
struct syn : public virtual_syntax { \
    static const std::vector<rule_t> _rules; \
    iter operator()(iter _b, iter _e) override { \
        for (const auto& _rule : _rules) { \
            iter _i = _b; \
            bool _parse_successfully = true; \
            for (const auto& _r : _rule) { \
                auto* const _k = _syntax_factory->get(_r); \
                iter _p = _k->operator()(_i, _e); \
                delete _k; \
                if (_p == _i) { \
                    _parse_successfully = false; \
                    break; \
                } \
                _i = _p; \
            } \
            if (_parse_successfully) return _i; \
        } \
        return _b; \
    } \
}

KEYWORD_DECL(if);
KEYWORD_DECL(elif);
KEYWORD_DECL(else);
KEYWORD_DECL(while);
KEYWORD_DECL(for);
KEYWORD_DECL(const);
KEYWORD_DECL(return);

SYNTAX_DECL(plus);
SYNTAX_DECL(minus);
SYNTAX_DECL(asterisk);
SYNTAX_DECL(slash);
SYNTAX_DECL(assignment);
SYNTAX_DECL(dot);
SYNTAX_DECL(comma);
SYNTAX_DECL(vertical);
SYNTAX_DECL(left_angle);
SYNTAX_DECL(right_angle);
SYNTAX_DECL(left_parentheses);
SYNTAX_DECL(right_parentheses);
SYNTAX_DECL(left_square);
SYNTAX_DECL(right_square);
SYNTAX_DECL(left_curly);
SYNTAX_DECL(right_curly);
SYNTAX_DECL(single_quote);
SYNTAX_DECL(double_quote);
SYNTAX_DECL(back_quote);
SYNTAX_DECL(tilde);
SYNTAX_DECL(backslash);
SYNTAX_DECL(question);
SYNTAX_DECL(colon);
SYNTAX_DECL(semicolon);
SYNTAX_DECL(exclamation);
SYNTAX_DECL(at);
SYNTAX_DECL(hashtag);
SYNTAX_DECL(dollar);
SYNTAX_DECL(percent);
SYNTAX_DECL(caret);
SYNTAX_DECL(ampersand);
SYNTAX_DECL(increment);
SYNTAX_DECL(decrement);
SYNTAX_DECL(arrow);

SYNTAX_DECL(identifier);
SYNTAX_DECL(integer);
SYNTAX_DECL(float);
SYNTAX_DECL(string);

RULED_SYNTAX_DECL(if_stmt);
RULED_SYNTAX_DECL(for_stmt);
RULED_SYNTAX_DECL(while_stmt);
RULED_SYNTAX_DECL(assign_stmt);
RULED_SYNTAX_DECL(compound_stmt);
RULED_SYNTAX_DECL(return_stmt);
RULED_SYNTAX_DECL(expr);

namespace __details__ {

RULED_SYNTAX_DECL(factor);

}




}

}

}

#endif // _ICY_SYNTAX_CFG_DEFINITION_HPP_