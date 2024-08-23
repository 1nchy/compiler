#ifndef _ICY_SYNTAX_CFG_DEFINITION_HPP_
#define _ICY_SYNTAX_CFG_DEFINITION_HPP_

#include <vector>
#include <type_traits>
#include <optional>
#include "lexical/lexeme.hpp"

#include "abstract_factory.hpp"

namespace icy {

namespace syntax {

namespace cfg {
    
using iter = std::vector<lexical::lexeme>::const_iterator;
using rule_t = std::vector<std::string>;

static const std::vector<rule_t> _s_empty_rules = {};

struct virtual_syntax;
struct virtual_syntax {
    virtual std::optional<ptrdiff_t> operator()(iter _b, iter _e, bool completely_match = false);
    virtual ~virtual_syntax() = default;
private:
    virtual const std::vector<rule_t>& rules() const;
};

auto* const _syntax_factory = icy::factory<virtual_syntax>::instance();
void _S_initialize_syntax_factory();
template <typename _Tp> void enroll(const std::string&);
virtual_syntax* get(const std::string&);

#define KEYWORD_DECL(key) \
struct keyword_##key : public virtual_syntax { \
    std::optional<ptrdiff_t> operator()(iter _b, iter _e, bool _completely_match) override { \
        std::ignore = _completely_match; \
        if (_b == _e) return std::nullopt; \
        if (_b->token() == lexical::token_t::tk_##key) { \
            return std::make_optional<ptrdiff_t>(1); \
        } \
        return std::nullopt; \
    } \
}
#define SYNTAX_DECL(syn) \
struct syntax_##syn : public virtual_syntax { \
    std::optional<ptrdiff_t> operator()(iter _b, iter _e, bool _completely_match) override { \
        std::ignore = _completely_match; \
        if (_b == _e) return std::nullopt; \
        if (_b->token() == lexical::token_t::tk_##syn) { \
            return std::make_optional<ptrdiff_t>(1); \
        } \
        return std::nullopt; \
    } \
}
#define RULED_SYNTAX_DECL(syn) \
struct syn : public virtual_syntax { \
private: \
    static const std::vector<rule_t> _rules; \
    const std::vector<rule_t>& rules() const override { return _rules; } \
}

struct syntax_epsilon : public virtual_syntax {
    std::optional<ptrdiff_t> operator()(iter _b, iter _e, bool _completely_match) override;
};

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

RULED_SYNTAX_DECL(expr_);
RULED_SYNTAX_DECL(term);
RULED_SYNTAX_DECL(term_);
RULED_SYNTAX_DECL(unary);
RULED_SYNTAX_DECL(factor);

}


template <typename _Tp> void enroll(const std::string& _s) {
    _syntax_factory->enroll<_Tp>(_s);
}

}

}

}

#endif // _ICY_SYNTAX_CFG_DEFINITION_HPP_