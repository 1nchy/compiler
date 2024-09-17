#ifndef _ICY_LEXICAL_DFA_FLOAT_HPP_
#define _ICY_LEXICAL_DFA_FLOAT_HPP_

#include "finite_state_machine.hpp"
#include "lexical/dfa/event.hpp"

namespace icy { namespace lexical { namespace dfa {
struct float_recognition : public fsm::state {
    using state = fsm::state;
    float_recognition& operator=(const float_recognition&);
    virtual label_type handle(const fsm::event&) override;
    virtual label_type handle(const digit&);
    virtual label_type handle(const alpha&);
    virtual label_type handle(const plus&);
    virtual label_type handle(const minus&);
    virtual label_type handle(const dot&);
    label_type transit(state* const) override;
    void assign(const state&) override;
    void entry() override {}
    void exit() override {}
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_float = false;
};

namespace __float__ {

struct A : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    void entry() override;
    label_type handle(const digit&) override;
};
struct ABEI : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const alpha&) override;
    label_type handle(const digit&) override;
    label_type handle(const dot&) override;
};
struct C : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const digit&) override;
};
struct CDEI : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const alpha&) override;
    label_type handle(const digit&) override;
};
struct FG : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const digit&) override;
    label_type handle(const plus&) override;
    label_type handle(const minus&) override;
};
struct G : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const digit&) override;
};
struct GHI : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const digit&) override;
};

extern fsm::context<float_recognition> dfa;

void initialize(void);

}

}}}

#endif // _ICY_LEXICAL_DFA_FLOAT_HPP_