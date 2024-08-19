#include "lexical/dfa/integer.hpp"

namespace icy { namespace lexical{ namespace dfa {

auto integer_recognition::operator=(const integer_recognition& _s)
-> integer_recognition& {
    if (&_s == this) return *this;
    _length = _s._length;
    _end_of_integer = _s._end_of_integer;
    return *this;
}
auto integer_recognition::handle(const fsm::event& _e) -> state* {
    _end_of_integer = true;
    return nullptr;
}
auto integer_recognition::handle(const digit& _e) -> state* {
    return handle(fsm::event(_e));
}
auto integer_recognition::transit(state* const _s) const -> state* {
    if (_end_of_integer) return nullptr;
    return _s;
}
auto integer_recognition::clone(const state* const _s) -> state* {
    const auto* const _p = dynamic_cast<const integer_recognition* const>(_s);
    assert(_p != nullptr);
    if (this != _s && _p != nullptr) *this = *_p;
    return this;
}

namespace __integer__ {

auto A::entry() -> void {
    _length = 0;
}
auto A::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<AB>()->clone(this);
}
auto AB::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<AB>()->clone(this);
}

}

}}}