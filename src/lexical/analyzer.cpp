#include "lexical/analyzer.hpp"

#include "lexical/dfa/integer.hpp"
#include "lexical/dfa/float.hpp"
#include "lexical/dfa/string.hpp"
#include "lexical/dfa/identifier.hpp"

namespace icy {

namespace lexical {

void initialize() {
    dfa::__integer__::initialize();
    dfa::__float__::initialize();
    dfa::__identifier__::initialize();
    dfa::__string__::initialize();
}

auto analyzer::scan(iter _b, iter _e) -> void {
    for (auto _i = _b; _i != _e;) {
        if (*_i == ' ') {
            ++_i; continue;
        }
        auto _l = parse_lexeme(_i, _e);
        if (_l.token() == token_t::tk_none) {
            return;
        }
        _lexeme_sequence.push_back(_l);
        _i += _l.attribute_value().size();
    }
}
auto analyzer::parse_lexeme(iter _b, iter _e) -> lexeme {
    size_t _max_length = 0;
    const size_t _length_integer = parse_integer_lexeme(_b, _e); _max_length = std::max(_max_length, _length_integer);
    const size_t _length_float = parse_float_lexeme(_b, _e); _max_length = std::max(_max_length, _length_float);
    const size_t _length_string = parse_string_lexeme(_b, _e); _max_length = std::max(_max_length, _length_string);
    const size_t _length_identifier = parse_identifier_lexeme(_b, _e); _max_length = std::max(_max_length, _length_identifier);
    if (_max_length == 0) {
        return parse_symbol_lexeme(_b, _e);
    }
    else if (_max_length == _length_integer) {
        return lexeme(token_t::tk_integer, std::string(_b, _b + _length_integer));
    }
    else if (_max_length == _length_float) {
        return lexeme(token_t::tk_float, std::string(_b, _b + _length_float));
    }
    else if (_max_length == _length_string) {
        return lexeme(token_t::tk_string, std::string(_b, _b + _length_string));
    }
    else if (_max_length == _length_identifier) {
        const std::string _word = std::string(_b, _b + _length_identifier);
        if (_keyword_token_map.contains(_word)) {
            return lexeme(string_2_token(_word), _word);
        }
        else {
            return lexeme(token_t::tk_identifier, _word);
        }
    }
    else {
        assert(false);
    }
}
auto analyzer::parse_integer_lexeme(iter _b, iter _e) -> size_t {
    auto& _dfa = dfa::__integer__::dfa;
    _dfa.start();
    _M_parse_lexeme(_dfa, _b, _e);
    size_t _result = _dfa.acceptable() ? _dfa.state()->length() : 0;
    _dfa.stop();
    return _result;
}
auto analyzer::parse_float_lexeme(iter _b, iter _e) -> size_t {
    auto& _dfa = dfa::__float__::dfa;
    _dfa.start();
    _M_parse_lexeme(_dfa, _b, _e);
    size_t _result = _dfa.acceptable() ? _dfa.state()->length() : 0;
    _dfa.stop();
    return _result;
}
auto analyzer::parse_string_lexeme(iter _b, iter _e) -> size_t {
    auto& _dfa = dfa::__string__::dfa;
    _dfa.start();
    _M_parse_lexeme(_dfa, _b, _e);
    size_t _result = _dfa.acceptable() ? _dfa.state()->length() : 0;
    _dfa.stop();
    return _result;
}
auto analyzer::parse_identifier_lexeme(iter _b, iter _e) -> size_t {
    auto& _dfa = dfa::__identifier__::dfa;
    _dfa.start();
    _M_parse_lexeme(_dfa, _b, _e);
    size_t _result = _dfa.acceptable() ? _dfa.state()->length() : 0;
    _dfa.stop();
    return _result;
}
auto analyzer::parse_symbol_lexeme(iter _b, iter _e) -> lexeme {
    const size_t _length_symbol = _symbol_tree.longest_match(_b, _e);
    if (_length_symbol == 0) {
        return lexeme();
    }
    const std::string _symbol(_b, _b + _length_symbol);
    return lexeme(string_2_token(_symbol), _symbol);
}
template <typename _Tp> auto analyzer::_M_parse_lexeme(fsm::context<_Tp>& _dfa, iter _b, iter _e) -> void {
    for (; _b != _e; ++_b) {
        const char _c = *_b;
        bool _result = fsm::character::handle(_dfa, _c);
        if (!_result) {
            return;
        }
    }
}

} // namespace lexical

} // namespace icy