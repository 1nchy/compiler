#include "lexical/dfa/integer.hpp"

namespace icy { namespace lexical{ namespace dfa {

using namespace fsm::character;    

auto integer_recognition::operator=(const integer_recognition& _s)
-> integer_recognition& {
    if (&_s == this) return *this;
    _length = _s._length;
    _end_of_integer = _s._end_of_integer;
    return *this;
}
auto integer_recognition::handle(const fsm::event& _e) -> label_type {
    _end_of_integer = true;
    return {};
}
auto integer_recognition::handle(const digit& _e) -> label_type {
    return handle(fsm::event(_e));
}
auto integer_recognition::transit() -> label_type {
    if (_end_of_integer) return state::label();
    return {};
}
auto integer_recognition::reset() -> void {
    _length = 0;
    _end_of_integer = false;
}
auto integer_recognition::assign(const state& _s) -> void {
    this->operator=(dynamic_cast<const integer_recognition&>(_s));
}

namespace __integer__ {

auto A::entry() -> void {
    _length = 0;
}
auto A::handle(const digit& _e) -> label_type {
    ++_length;
    return AB::label();
}
auto AB::handle(const digit& _e) -> label_type {
    ++_length;
    return AB::label();
}

fsm::context<integer_recognition> dfa = fsm::context<integer_recognition>();

void initialize(void) {
    dfa.enroll<A, AB>();
    dfa.accept<AB>();
    dfa.default_entry<A>();
}

}

}}}