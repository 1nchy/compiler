#ifndef _ICY_LEXICAL_DFA_FLOAT_HPP_
#define _ICY_LEXICAL_DFA_FLOAT_HPP_

#include "finite_state_machine.hpp"
#include "lexical/dfa/event.hpp"

namespace icy { namespace lexical { namespace dfa {
struct float_recognition : public fsm::state {
    using state = fsm::state;
    float_recognition& operator=(const float_recognition&);
    virtual state* handle(const fsm::event&) override;
    virtual state* handle(const digit&);
    virtual state* handle(const alpha&);
    virtual state* handle(const plus&);
    virtual state* handle(const minus&);
    virtual state* handle(const dot&);
    state* transit(state* const) const override;
    state* clone(const state* const) override;
    void entry() override {}
    void exit() override {}
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_float = false;
};

namespace __float__ {

struct A : public float_recognition {
    using state = fsm::state;
    void entry() override;
    state* handle(const digit&) override;
};
struct ABEI : public float_recognition {
    using state = fsm::state;
    state* handle(const alpha&) override;
    state* handle(const digit&) override;
    state* handle(const dot&) override;
};
struct C : public float_recognition {
    using state = fsm::state;
    state* handle(const digit&) override;
};
struct CDEI : public float_recognition {
    using state = fsm::state;
    state* handle(const alpha&) override;
    state* handle(const digit&) override;
};
struct FG : public float_recognition {
    using state = fsm::state;
    state* handle(const digit&) override;
    state* handle(const plus&) override;
    state* handle(const minus&) override;
};
struct G : public float_recognition {
    using state = fsm::state;
    state* handle(const digit&) override;
};
struct GHI : public float_recognition {
    using state = fsm::state;
    state* handle(const digit&) override;
};

}

}}}

#endif // _ICY_LEXICAL_DFA_FLOAT_HPP_