#ifndef _ICY_LEXICAL_DFA_INTEGER_HPP_
#define _ICY_LEXICAL_DFA_INTEGER_HPP_

#include "finite_state_machine.hpp"
#include "event.hpp"

namespace icy { namespace lexical { namespace dfa {
struct integer_recognition : public fsm::state {
    using state = fsm::state;
    integer_recognition& operator=(const integer_recognition&);
    virtual state* handle(const fsm::event&) override;
    virtual state* handle(const digit&);
    state* transit(state* const) const override;
    state* clone(const state* const) override;
    void entry() override {}
    void exit() override {}
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_integer = false;
};

namespace __integer__ {

struct A : public integer_recognition {
    using state = fsm::state;
    void entry() override;
    state* handle(const digit&) override;
};
struct AB : public integer_recognition {
    using state = fsm::state;
    state* handle(const digit&) override;
};

}

}}}

#endif // _ICY_LEXICAL_DFA_INTEGER_HPP_