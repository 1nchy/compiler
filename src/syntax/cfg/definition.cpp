#include "syntax/cfg/definition.hpp"

#include "lexical/lexeme.hpp"

#include <cassert>

namespace icy {

namespace syntax {

namespace cfg {

void initialize() {
    enroll<syntax_epsilon>("EPSILON");

    enroll<if_stmt>("IF_STMT");
    // enroll<for_stmt>("FOR_STMT");
    // enroll<while_stmt>("WHILE_STMT");
    // enroll<assign_stmt>("ASSIGN_MENT");
    enroll<compound_stmt>("COMPOUND_STMT");
    // enroll<return_stmt>("RETURN_STMT");
    enroll<expr>("EXPR");    

    enroll<keyword_if>("IF");
    enroll<keyword_elif>("ELIF");
    enroll<keyword_else>("ELSE");
    // enroll<keyword_while>("WHILE");
    // enroll<keyword_for>("FOR");
    enroll<keyword_const>("CONST");
    enroll<keyword_return>("RETURN");

    enroll<syntax_integer>("INTEGER");
    enroll<syntax_float>("FLOAT");
    enroll<syntax_string>("STRING");
    enroll<syntax_identifier>("IDENTIFIER");

    enroll<__details__::expr_>("EXPR_");
    enroll<__details__::expr__>("EXPR__");
    enroll<__details__::term>("TERM");
    enroll<__details__::term_>("TERM_");
    enroll<__details__::unary>("UNARY");
    enroll<__details__::factor>("FACTOR");

    enroll<syntax_plus>("PLUS");
    enroll<syntax_minus>("MINUS");
    enroll<syntax_asterisk>("ASTERISK");
    enroll<syntax_slash>("SLASH");
    enroll<syntax_left_parentheses>("LEFT_PARENTHESES");
    enroll<syntax_right_parentheses>("RIGHT_PARENTHESES");
    enroll<syntax_left_curly>("LEFT_CURLY");
    enroll<syntax_right_curly>("RIGHT_CURLY");
    enroll<syntax_comma>("COMMA");
}
virtual_syntax* get(const std::string& _s) {
    return _syntax_factory->get(_s);
}

auto virtual_syntax::operator()(node* const _n, iter _b, iter _e, bool _completely_match) -> std::optional<ptrdiff_t> {
    assert(_n->syntax() == this);
    this->_lexeme_begin = _b;
    for (const auto& _rule : this->rules()) {
        iter _i = _b;
        bool _match_failure = false;
        _n->clear();
        for (const auto& _r : _rule) {
            auto* const _k = cfg::get(_r);
            _n->push(_k);
            auto _option = _k->operator()(_n->children().back(), _i, _e);
            // delete _k;
            if (!_option.has_value()) {
                _n->clear();
                _match_failure = true;
                break;
            }
            _i += _option.value();
        }
        if (!_match_failure && (!_completely_match || _i == _e)) {
            this->_lexeme_end = _i;
            return std::make_optional<ptrdiff_t>(_i - _b);
        }
    }
    _n->clear();
    return std::nullopt;
}
auto virtual_syntax::label() const -> const std::string& {
    return _s_empty_label;
}
auto virtual_syntax::begin() const -> iter {
    return this->_lexeme_begin;
}
auto virtual_syntax::end() const -> iter {
    return this->_lexeme_end;
}
auto virtual_syntax::rules() const -> const std::vector<rule_t>& {
    return _s_empty_rules;
}
auto syntax_epsilon::operator()(node* const _n, iter _b, iter _e, bool _completely_match) -> std::optional<ptrdiff_t> {
    this->_lexeme_begin = _b;
    this->_lexeme_end = _b;
    return std::make_optional<ptrdiff_t>(0);
}

const std::vector<rule_t> if_stmt::_rules = {
{
    "IF", "LEFT_PARENTHESES", "EXPR", "RIGHT_PARENTHESES", "COMPOUND_STMT",
    "ELSE", "COMPOUND_STMT"
}
};
const std::vector<rule_t> compound_stmt::_rules = {
{
    "LEFT_CURLY", "RIGHT_CURLY"
}
};
const std::vector<rule_t> expr::_rules = {
{
    "TERM", "EXPR_"
}
};

const std::string if_stmt::_label = "IF_STMT";
const std::string compound_stmt::_label = "COMPOUND_STMT";
const std::string expr::_label = "EXPR";

namespace __details__ {

const std::vector<rule_t> expr_::_rules = {
{
    "PLUS", "TERM", "EXPR__"
}, {
    "MINUS", "TERM", "EXPR__"
}, {
    "EXPR__"
}
};
const std::vector<rule_t> expr__::_rules = {
{
    "COMMA", "EXPR", "EXPR__"
}, {
    "EPSILON"
}
};
const std::vector<rule_t> term::_rules = {
{
    "UNARY", "TERM_"
}
};
const std::vector<rule_t> term_::_rules = {
{
    "ASTERISK", "UNARY", "TERM_"
}, {
    "SLASH", "UNARY", "TERM_"
}, {
    "EPSILON"
}
};
const std::vector<rule_t> unary::_rules = {
{
    "MINUS", "FACTOR"
}, {
    "FACTOR"
}
};
const std::vector<rule_t> factor::_rules = {
{
    "INTEGER"
}, {
    "FLOAT"
}, {
    "IDENTIFIER"
}, {
    "LEFT_PARENTHESES", "EXPR", "RIGHT_PARENTHESES"
}
};

}

}

}

}