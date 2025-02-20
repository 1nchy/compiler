#ifndef _ICY_LEXICAL_DFA_FLOAT_HPP_
#define _ICY_LEXICAL_DFA_FLOAT_HPP_

#include "finite_state_machine.hpp"

namespace icy { namespace lexical { namespace dfa {
struct float_recognition : public fsm::state {
    using state = fsm::state;
    float_recognition& operator=(const float_recognition&);
    virtual label_type handle(const fsm::event&) override;
    virtual label_type handle(const fsm::character::digit&);
    virtual label_type handle(const fsm::character::alpha&);
    virtual label_type handle(const fsm::character::plus&);
    virtual label_type handle(const fsm::character::minus&);
    virtual label_type handle(const fsm::character::dot&);
    label_type transit() override;
    void reset() override;
    void assign(const state&) override;
    size_t length() const { return _length; }
    size_t _length = 0;
    bool _end_of_float = false;
};

namespace __float__ {

struct A : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    void entry() override;
    label_type handle(const fsm::character::digit&) override;
};
struct ABEI : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::character::alpha&) override;
    label_type handle(const fsm::character::digit&) override;
    label_type handle(const fsm::character::dot&) override;
};
struct C : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::character::digit&) override;
};
struct CDEI : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::character::alpha&) override;
    label_type handle(const fsm::character::digit&) override;
};
struct FG : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::character::digit&) override;
    label_type handle(const fsm::character::plus&) override;
    label_type handle(const fsm::character::minus&) override;
};
struct G : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::character::digit&) override;
};
struct GHI : public float_recognition {
    FSM_STATE_LABEL
    using state = fsm::state;
    label_type handle(const fsm::character::digit&) override;
};

extern fsm::context<float_recognition> dfa;

void initialize(void);

}

}}}

#endif // _ICY_LEXICAL_DFA_FLOAT_HPP_