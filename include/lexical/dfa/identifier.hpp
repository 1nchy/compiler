#ifndef _ICY_LEXICAL_DFA_IDENTIFIER_HPP_
#define _ICY_LEXICAL_DFA_IDENTIFIER_HPP_

#include "finite_state_machine.hpp"
#include "lexical/dfa/event.hpp"

namespace icy { namespace lexical { namespace dfa {
struct identifier_recognition : public fsm::state {
    using state = fsm::state;
    identifier_recognition& operator=(const identifier_recognition&);
    virtual label_type handle(const fsm::event&) override;
    virtual label_type handle(const digit&);
    virtual label_type handle(const alpha&);
    label_type transit(state* const) override;
    void assign(const state&) override;
    void entry() override {}
    void exit() override {}
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_identifier = false;
};

namespace __identifier__ {

struct A : public identifier_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    void entry() override;
    label_type handle(const alpha&) override;
};
struct B : public identifier_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const alpha&) override;
    label_type handle(const digit&) override;
};

extern fsm::context<identifier_recognition> dfa;

void initialize(void);

}

}}}

#endif // _ICY_LEXICAL_DFA_IDENTIFIER_HPP_