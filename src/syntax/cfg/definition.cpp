#include "syntax/cfg/definition.hpp"

#include "lexical/lexeme.hpp"

namespace icy {

namespace syntax {

namespace cfg {

void _S_initialize_syntax_factory() {
    _syntax_factory->enroll<if_stmt>("IF_STMT");
    // _syntax_factory->enroll<for_stmt>("FOR_STMT");
    // _syntax_factory->enroll<while_stmt>("WHILE_STMT");
    // _syntax_factory->enroll<assign_stmt>("ASSIGN_MENT");
    _syntax_factory->enroll<compound_stmt>("COMPOUND_STMT");
    // _syntax_factory->enroll<return_stmt>("RETURN_STMT");
    _syntax_factory->enroll<expr>("EXPR");    

    _syntax_factory->enroll<keyword_if>("IF");
    _syntax_factory->enroll<keyword_elif>("ELIF");
    _syntax_factory->enroll<keyword_else>("ELSE");
    // _syntax_factory->enroll<keyword_while>("WHILE");
    // _syntax_factory->enroll<keyword_for>("FOR");
    _syntax_factory->enroll<keyword_const>("CONST");
    _syntax_factory->enroll<keyword_return>("RETURN");

    _syntax_factory->enroll<syntax_integer>("INTEGER");
    _syntax_factory->enroll<syntax_float>("FLOAT");
    _syntax_factory->enroll<syntax_string>("STRING");
    _syntax_factory->enroll<syntax_identifier>("IDENTIFIER");

    _syntax_factory->enroll<__details__::factor>("FACTOR");

    _syntax_factory->enroll<syntax_plus>("PLUS");
    _syntax_factory->enroll<syntax_minus>("MINUS");
    _syntax_factory->enroll<syntax_asterisk>("ASTERISK");
    _syntax_factory->enroll<syntax_slash>("SLASH");
    _syntax_factory->enroll<syntax_left_parentheses>("LEFT_PARENTHESES");
    _syntax_factory->enroll<syntax_right_parentheses>("RIGHT_PARENTHESES");
    _syntax_factory->enroll<syntax_left_curly>("LEFT_CURLY");
    _syntax_factory->enroll<syntax_right_curly>("RIGHT_CURLY");
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
    "FACTOR"
}, {
    "FACTOR", "PLUS", "EXPR"
}, {
    "FACTOR", "MINUS", "EXPR"
}, {
    "FACTOR", "ASTERISK", "EXPR"
}, {
    "FACTOR", "SLASH", "EXPR"
}, {
    "LEFT_PARENTHESES", "EXPR", "RIGHT_PARENTHESES"
}
};

namespace __details__ {

const std::vector<rule_t> factor::_rules = {{
    "INTEGER"
    }, {
    "FLOAT"
    }, {
    "IDENTIFIER"
    }
};

}

}

}

}