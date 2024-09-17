#include "lexical/dfa/string.hpp"

namespace icy { namespace lexical { namespace dfa {

auto string_recognition::operator=(const string_recognition& _s)
-> string_recognition& {
    if (&_s == this) return *this;
    _length = _s._length;
    _end_of_string = _s._end_of_string;
    return *this;
}
auto string_recognition::handle(const fsm::event& _e) -> label_type {
    _end_of_string = true;
    return {};
}
auto string_recognition::handle(const backslash& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto string_recognition::handle(const double_quote& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto string_recognition::transit(state* const _s) -> label_type {
    if (_end_of_string) throw fsm::state_error();
    return {};
}
auto string_recognition::assign(const state& _s) -> void {
    this->operator=(dynamic_cast<const string_recognition&>(_s));
}

namespace __string__ {

auto A::entry() -> void {
    _length = 0;
}
auto A::handle(const double_quote& _e) -> label_type {
    ++_length;
    return BE::label();
}
auto BE::handle(const fsm::event& _e) -> label_type {
    ++_length;
    return BDE::label();
}
auto BE::handle(const backslash& _e) -> label_type {
    ++_length;
    return C::label();
}
auto BE::handle(const double_quote& _e) -> label_type {
    ++_length;
    return F::label();
}
auto C::handle(const fsm::event& _e) -> label_type {
    ++_length;
    return BDE::label();
}
auto BDE::handle(const fsm::event& _e) -> label_type {
    ++_length;
    return BDE::label();
}
auto BDE::handle(const backslash& _e) -> label_type {
    ++_length;
    return C::label();
}
auto BDE::handle(const double_quote& _e) -> label_type {
    ++_length;
    return F::label();
}

fsm::context<string_recognition> dfa = fsm::context<string_recognition>();

void initialize(void) {
    dfa.enroll<A>();
    dfa.enroll<BE>();
    dfa.enroll<C>();
    dfa.enroll<BDE>();
    dfa.enroll<F>();

    dfa.accept<F>();

    dfa.default_entry<A>();
}

}

}}}