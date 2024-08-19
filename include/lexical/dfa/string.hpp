#ifndef _ICY_LEXICAL_DFA_STRING_HPP_
#define _ICY_LEXICAL_DFA_STRING_HPP_

#include "finite_state_machine.hpp"
#include "lexical/dfa/event.hpp"

namespace icy { namespace lexical { namespace dfa {
struct string_recognition : public fsm::state {
    using state = fsm::state;
    string_recognition& operator=(const string_recognition&);
    virtual state* handle(const fsm::event&) override;
    virtual state* handle(const backslash&);
    virtual state* handle(const double_quote&);
    state* transit(state* const) const override;
    state* clone(const state* const) override;
    void entry() override {}
    void exit() override {}
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_string = false;
};

namespace __string__ {

struct A : public string_recognition {
    using state = fsm::state;
    void entry() override;
    state* handle(const double_quote&) override;
};
struct BE : public string_recognition {
    using state = fsm::state;
    state* handle(const fsm::event&) override;
    state* handle(const backslash&) override;
    state* handle(const double_quote&) override;
};
struct C : public string_recognition {
    using state = fsm::state;
    state* handle(const fsm::event&) override;
};
struct BDE : public string_recognition {
    using state = fsm::state;
    state* handle(const fsm::event&) override;
    state* handle(const backslash&) override;
    state* handle(const double_quote&) override;
};
struct F : public string_recognition {
    using state = fsm::state;
};

}

}}}
#endif // _ICY_LEXICAL_DFA_STRING_HPP_