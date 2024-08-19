#ifndef _ICY_LEXICAL_DFA_EVENT_HPP_
#define _ICY_LEXICAL_DFA_EVENT_HPP_

#include "finite_state_machine.hpp"

#include "lexical/lexeme.hpp"

namespace icy { namespace lexical { namespace dfa {
    bool is_alpha(char _c);
    struct alpha : public fsm::event { // a-z A-Z _
        alpha(char _c) : _c(_c) {}
        const char _c;
    };

    bool is_digit(char _c);
    struct digit : public fsm::event {
        digit(char _c) : _c(_c) {}
        const char _c;
    }; // 0-9

    struct plus : public fsm::event {}; // +
    struct minus : public fsm::event {}; // -
    struct asterisk : public fsm::event {}; // *
    struct slash : public fsm::event {}; // /
    struct assignment : public fsm::event {}; // =
    struct dot : public fsm::event {}; // .
    struct comma : public fsm::event {}; // ,
    struct vertical : public fsm::event {}; // |

    struct left_angle : public fsm::event {}; // <
    struct right_angle : public fsm::event {}; // >
    struct left_parentheses : public fsm::event {}; // (
    struct right_parentheses : public fsm::event {}; // )
    struct left_square : public fsm::event {}; // [
    struct right_square : public fsm::event {}; // ]
    struct left_curly : public fsm::event {}; // {
    struct right_curly : public fsm::event {}; // }

    struct single_quote : public fsm::event {}; // '
    struct double_quote : public fsm::event {}; // "
    struct back_quote : public fsm::event {}; // ~
    struct tilde : public fsm::event {}; // ~
    struct backslash : public fsm::event {}; // 
    struct question : public fsm::event {}; // ?
    struct colon : public fsm::event {}; // :
    struct semicolon : public fsm::event {}; // ;

    struct exclamation : public fsm::event {}; // !
    struct at : public fsm::event {}; // @
    struct hashtag : public fsm::event {}; // #
    struct dollar : public fsm::event {}; // $
    struct percent : public fsm::event {}; // %
    struct caret : public fsm::event {}; // ^
    struct ampersand : public fsm::event {}; // &
}}}

#endif // _ICY_LEXICAL_DFA_EVENT_HPP_