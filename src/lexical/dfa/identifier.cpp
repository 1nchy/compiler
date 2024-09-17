#include "lexical/dfa/identifier.hpp"

namespace icy { namespace lexical{ namespace dfa {

auto identifier_recognition::operator=(const identifier_recognition& _s)
-> identifier_recognition& {
    if (&_s == this) return *this;
    _length = _s._length;
    _end_of_identifier = _s._end_of_identifier;
    return *this;
}
auto identifier_recognition::handle(const fsm::event& _e) -> label_type {
    _end_of_identifier = true;
    return {};
}
auto identifier_recognition::handle(const digit& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto identifier_recognition::handle(const alpha& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto identifier_recognition::transit(state* const _s) -> label_type {
    if (_end_of_identifier) throw fsm::state_error();
    return {};
}
auto identifier_recognition::assign(const state& _s) -> void {
    this->operator=(dynamic_cast<const identifier_recognition&>(_s));
}

namespace __identifier__ {

auto A::entry() -> void {
    _length = 0;
}
auto A::handle(const alpha& _e) -> label_type {
    ++_length;
    return B::label();
}
auto B::handle(const alpha& _e) -> label_type {
    ++_length;
    return B::label();
}
auto B::handle(const digit& _e) -> label_type {
    ++_length;
    return B::label();
}

fsm::context<identifier_recognition> dfa = fsm::context<identifier_recognition>();

void initialize(void) {
    dfa.enroll<A>();
    dfa.enroll<B>();

    dfa.accept<B>();

    dfa.default_entry<A>();
}

}

}}}