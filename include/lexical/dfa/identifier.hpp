#ifndef _ICY_LEXICAL_DFA_IDENTIFIER_HPP_
#define _ICY_LEXICAL_DFA_IDENTIFIER_HPP_

#include "finite_state_machine.hpp"
#include "lexical/dfa/event.hpp"

namespace icy { namespace lexical { namespace dfa {
struct identifier_recognition : public fsm::state {
    using state = fsm::state;
    identifier_recognition& operator=(const identifier_recognition&);
    virtual state* handle(const fsm::event&) override;
    virtual state* handle(const digit&);
    virtual state* handle(const alpha&);
    state* transit(state* const) const override;
    state* clone(const state* const) override;
    void entry() override {}
    void exit() override {}
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_identifier = false;
};

namespace __identifier__ {

struct A : public identifier_recognition {
    using state = fsm::state;
    void entry() override;
    state* handle(const alpha&) override;
};
struct B : public identifier_recognition {
    using state = fsm::state;
    state* handle(const alpha&) override;
    state* handle(const digit&) override;
};

}

}}}

#endif // _ICY_LEXICAL_DFA_IDENTIFIER_HPP_