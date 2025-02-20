#ifndef _ICY_LEXICAL_DFA_IDENTIFIER_HPP_
#define _ICY_LEXICAL_DFA_IDENTIFIER_HPP_

#include "finite_state_machine.hpp"

namespace icy { namespace lexical { namespace dfa {
struct identifier_recognition : public fsm::state {
    using state = fsm::state;
    identifier_recognition& operator=(const identifier_recognition&);
    virtual label_type handle(const fsm::event&) override;
    virtual label_type handle(const fsm::character::digit&);
    virtual label_type handle(const fsm::character::alpha&);
    virtual label_type handle(const fsm::character::underline&);
    label_type transit() override;
    void reset() override;
    void assign(const state&) override;
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_identifier = false;
};

namespace __identifier__ {

struct A : public identifier_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    void entry() override;
    label_type handle(const fsm::character::alpha&) override;
    label_type handle(const fsm::character::underline&) override;
};
struct B : public identifier_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::character::alpha&) override;
    label_type handle(const fsm::character::underline&) override;
    label_type handle(const fsm::character::digit&) override;
};

extern fsm::context<identifier_recognition> dfa;

void initialize(void);

}

}}}

#endif // _ICY_LEXICAL_DFA_IDENTIFIER_HPP_