#include "lexical/dfa/float.hpp"

namespace icy { namespace lexical{ namespace dfa {

auto float_recognition::operator=(const float_recognition& _s)
-> float_recognition& {
    if (&_s == this) return *this;
    _length = _s._length;
    _end_of_float = _s._end_of_float;
    return *this;
}
auto float_recognition::handle(const fsm::event& _e) -> label_type {
    _end_of_float = true;
    return {};
}
auto float_recognition::handle(const digit& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto float_recognition::handle(const alpha& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto float_recognition::handle(const plus& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto float_recognition::handle(const minus& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto float_recognition::handle(const dot& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto float_recognition::transit(state* const _s) -> label_type {
    if (_end_of_float) throw fsm::state_error();
    return {};
}
auto float_recognition::assign(const state& _s) -> void {
    this->operator=(dynamic_cast<const float_recognition&>(_s));
}

namespace __float__ {

auto A::entry() -> void {
    _length = 0;
}
auto A::handle(const digit& _e) -> label_type {
    ++_length;
    return ABEI::label();
}
auto ABEI::handle(const alpha& _e) -> label_type {
    if (_e._c != 'e') {
        _end_of_float = true;
        throw fsm::state_error();
    }
    ++_length;
    return FG::label();
}
auto ABEI::handle(const digit& _e) -> label_type {
    ++_length;
    return ABEI::label();
}
auto ABEI::handle(const dot& _e) -> label_type {
    ++_length;
    return C::label();
}
auto C::handle(const digit& _e) -> label_type {
    ++_length;
    return CDEI::label();
}
auto CDEI::handle(const alpha& _e) -> label_type {
    if (_e._c != 'e') {
        _end_of_float = true;
        throw fsm::state_error();
    }
    ++_length;
    return CDEI::label();
}
auto CDEI::handle(const digit& _e) -> label_type {
    ++_length;
    return CDEI::label();
}
auto FG::handle(const digit& _e) -> label_type {
    ++_length;
    return GHI::label();
}
auto FG::handle(const plus& _e) -> label_type {
    ++_length;
    return GHI::label();
}
auto FG::handle(const minus& _e) -> label_type {
    ++_length;
    return GHI::label();
}
auto G::handle(const digit& _e) -> label_type {
    ++_length;
    return GHI::label();
}
auto GHI::handle(const digit& _e) -> label_type {
    ++_length;
    return GHI::label();
}

fsm::context<float_recognition> dfa = fsm::context<float_recognition>();

void initialize(void) {
    dfa.enroll<A>();
    dfa.enroll<ABEI>();
    dfa.enroll<C>();
    dfa.enroll<CDEI>();
    dfa.enroll<FG>();
    dfa.enroll<G>();
    dfa.enroll<GHI>();

    dfa.accept<ABEI>();
    dfa.accept<CDEI>();
    dfa.accept<GHI>();

    dfa.default_entry<A>();
}

}

}}}