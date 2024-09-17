#ifndef _ICY_LEXICAL_DFA_STRING_HPP_
#define _ICY_LEXICAL_DFA_STRING_HPP_

#include "finite_state_machine.hpp"
#include "lexical/dfa/event.hpp"

namespace icy { namespace lexical { namespace dfa {
struct string_recognition : public fsm::state {
    using state = fsm::state;
    string_recognition& operator=(const string_recognition&);
    virtual label_type handle(const fsm::event&) override;
    virtual label_type handle(const backslash&);
    virtual label_type handle(const double_quote&);
    label_type transit(state* const) override;
    void assign(const state&) override;
    void entry() override {}
    void exit() override {}
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_string = false;
};

namespace __string__ {

struct A : public string_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    void entry() override;
    label_type handle(const double_quote&) override;
};
struct BE : public string_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::event&) override;
    label_type handle(const backslash&) override;
    label_type handle(const double_quote&) override;
};
struct C : public string_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::event&) override;
};
struct BDE : public string_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::event&) override;
    label_type handle(const backslash&) override;
    label_type handle(const double_quote&) override;
};
struct F : public string_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
};

extern fsm::context<string_recognition> dfa;

void initialize(void);

}

}}}
#endif // _ICY_LEXICAL_DFA_STRING_HPP_