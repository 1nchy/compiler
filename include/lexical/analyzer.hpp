#ifndef _ICY_LEXICAL_ANALYZER_HPP_
#define _ICY_LEXICAL_ANALYZER_HPP_

#include <string>

#include "lexical/lexeme.hpp"

#include "finite_state_machine.hpp"

namespace icy {

namespace lexical {

class analyzer;

void initialize();

class analyzer {
public:
    analyzer() = default;
    analyzer(const analyzer&) = delete;
    analyzer& operator=(const analyzer&) = delete;
    ~analyzer() = default;
    using iter = std::string::const_iterator;
public: // interface
    void scan(iter, iter);
    const auto& lexeme_sequence() const { return _lexeme_sequence; }
private:
    lexeme parse_lexeme(iter, iter);
    size_t parse_integer_lexeme(iter, iter);
    size_t parse_float_lexeme(iter, iter);
    size_t parse_string_lexeme(iter, iter);
    size_t parse_identifier_lexeme(iter, iter);
    lexeme parse_symbol_lexeme(iter, iter);
    template <typename _Tp> void _M_parse_lexeme(fsm::context<_Tp>&, iter, iter);
private:
    std::vector<lexeme> _lexeme_sequence;
};

} // namespace lexical

} // namespace icy

#endif // _ICY_LEXICAL_ANALYZER_HPP_