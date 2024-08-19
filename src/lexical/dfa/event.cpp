#include "lexical/dfa/event.hpp"

namespace icy { namespace lexical { namespace dfa {
    bool is_alpha(char _c) {
        return _alpha_set.contains(_c);
    }

    bool is_digit(char _c) {
        return _digit_set.contains(_c);
    }

    bool is_symbol(char _c) {
        return _symbol_char_set.contains(_c);
    }
}}}