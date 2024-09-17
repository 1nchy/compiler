#ifndef _ICY_LEXICAL_DFA_INTEGER_HPP_
#define _ICY_LEXICAL_DFA_INTEGER_HPP_

#include "finite_state_machine.hpp"
#include "event.hpp"

namespace icy { namespace lexical { namespace dfa {
struct integer_recognition : public fsm::state {
    using state = fsm::state;
    integer_recognition& operator=(const integer_recognition&);
    virtual label_type handle(const fsm::event&) override;
    virtual label_type handle(const digit&);
    label_type transit(state* const) override;
    void assign(const state&) override;
    void entry() override {}
    void exit() override {}
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_integer = false;
};

namespace __integer__ {

struct A : public integer_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    void entry() override;
    label_type handle(const digit&) override;
};
struct AB : public integer_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const digit&) override;
};

extern fsm::context<integer_recognition> dfa;

void initialize(void);

}

}}}

#endif // _ICY_LEXICAL_DFA_INTEGER_HPP_