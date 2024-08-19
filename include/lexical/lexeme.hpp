#ifndef _ICY_LEXICAL_LEXEME_HPP_
#define _ICY_LEXICAL_LEXEME_HPP_

#include <cstddef>
#include <string>
#include <unordered_set>

#include "trie_tree.hpp"

namespace icy {

typedef enum {
    tk_none,
    tk_identifier, tk_keyword,
    tk_integer, tk_float,
    tk_string,

    tk_plus, // +
    tk_minus, // -
    tk_asterisk, // *
    tk_slash, // /
    tk_assignment, // =
    tk_dot, // .
    tk_comma, // ,
    tk_vertical, // |
    tk_left_angle, // <
    tk_right_angle, // >
    tk_left_parentheses, // (
    tk_right_parentheses, // )
    tk_left_square, // [
    tk_right_square, // ]
    tk_left_curly, // {
    tk_right_curly, // }
    tk_single_quote, // '
    tk_double_quote, // "
    tk_back_quote, // `
    tk_tilde, // ~
    tk_backslash, // 
    tk_question, // ?
    tk_colon, // :
    tk_semicolon, // ;
    tk_exclamation, // !
    tk_at, // @
    tk_hashtag, // #
    tk_dollar, // $
    tk_percent, // %
    tk_caret, // ^
    tk_ampersand, // &
} token_t;

}

#endif // _ICY_LEXICAL_LEXEME_HPP_