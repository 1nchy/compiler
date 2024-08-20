#ifndef _ICY_LEXICAL_LEXEME_HPP_
#define _ICY_LEXICAL_LEXEME_HPP_

#include <cstddef>
#include <string>
#include <unordered_set>

#include "trie_tree.hpp"

namespace icy {

namespace lexical {

typedef enum {
    tk_none,
    tk_identifier, // tk_keyword,
    tk_integer, tk_float,
    tk_string,

    tk_if, // if
    tk_elif, // elif
    tk_else, // else
    tk_while, // while
    tk_for, // for
    tk_const, // const
    tk_return, // return

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

    tk_increment, // ++
    tk_decrement, // --
    tk_arrow, // ->
} token_t;

const icy::trie_tree _keyword_tree = {
    "if",
    "elif",
    "else",
    "while",
    "for",
    "const",
    "return",
};
const std::unordered_set<char> _digit_set = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
};
const std::unordered_set<char> _alpha_set = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z',
    '_'
};
const std::unordered_set<char> _symbol_char_set = {
    '+', '-', '*', '/', '=', '.', ',', '|',
    '<', '>', '(', ')', '[', ']', '{', '}',
    '\'', '\"', '`', '~', '\\', '?', ':', ';',
    '!', '@', '#', '$', '%', '^', '&',
};
const icy::trie_tree _symbol_tree = {
    "+", "-", "*", "/", "=", ".", ",", "|",
    "<", ">", "(", ")", "[", "]", "{", "}",
    "\"", "\"", "`", "~", "\\", "?", ":", ";",
    "!", "@", "#", "$", "%", "^", "&",
    "++", "--", "->",
};
const std::unordered_map<std::string, token_t> _symbol_token_map = {
    {"+", token_t::tk_plus},
    {"-", token_t::tk_minus},
    {"*", token_t::tk_asterisk},
    {"/", token_t::tk_slash},
    {"=", token_t::tk_assignment},
    {".", token_t::tk_dot},
    {",", token_t::tk_comma},
    {"|", token_t::tk_vertical},
    {"<", token_t::tk_left_angle},
    {">", token_t::tk_right_angle},
    {"(", token_t::tk_left_parentheses},
    {")", token_t::tk_right_parentheses},
    {"[", token_t::tk_left_square},
    {"]", token_t::tk_right_square},
    {"{", token_t::tk_left_curly},
    {"}", token_t::tk_right_curly},
    {"'", token_t::tk_single_quote},
    {"\"", token_t::tk_double_quote},
    {"`", token_t::tk_back_quote},
    {"~", token_t::tk_tilde},
    {"\\", token_t::tk_backslash},
    {"?", token_t::tk_question},
    {":", token_t::tk_colon},
    {";", token_t::tk_semicolon},
    {"!", token_t::tk_exclamation},
    {"@", token_t::tk_at},
    {"#", token_t::tk_hashtag},
    {"$", token_t::tk_dollar},
    {"%", token_t::tk_percent},
    {"^", token_t::tk_caret},
    {"&", token_t::tk_ampersand},

    {"++", token_t::tk_increment},
    {"--", token_t::tk_decrement},
    {"->", token_t::tk_arrow},
};
const std::unordered_map<std::string, token_t> _keyword_token_map = {
    {"if", token_t::tk_if},
    {"elif", token_t::tk_elif},
    {"else", token_t::tk_else},
    {"while", token_t::tk_while},
    {"for", token_t::tk_for},
    {"const", token_t::tk_const},
    {"return", token_t::tk_return},
};

inline auto string_2_token(const std::string& _s) -> token_t {
    if (_symbol_token_map.contains(_s))
        return _symbol_token_map.at(_s);
    else if (_keyword_token_map.contains(_s))
        return _keyword_token_map.at(_s);
    else
        return token_t::tk_none;
}

class lexeme {
public:
    using attribute_value_t = std::string;
    lexeme(token_t _tn = token_t::tk_none, attribute_value_t _v = "") : _token(_tn), _value(_v) {}
    lexeme(const lexeme&) = default;
    lexeme& operator=(const lexeme&) = delete;
    ~lexeme() = default;
    token_t token() const { return _token; }
    const attribute_value_t& attribute_value() const { return _value; }
private:
    const token_t _token;
    const attribute_value_t _value;
};

} // namespace lexical

} // namespace icy

#endif // _ICY_LEXICAL_LEXEME_HPP_