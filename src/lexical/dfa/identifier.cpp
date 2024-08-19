#include "lexical/dfa/identifier.hpp"

namespace icy { namespace lexical{ namespace dfa {

auto identifier_recognition::operator=(const identifier_recognition& _s)
-> identifier_recognition& {
    if (&_s == this) return *this;
    _length = _s._length;
    _end_of_identifier = _s._end_of_identifier;
    return *this;
}
auto identifier_recognition::handle(const fsm::event& _e) -> state* {
    _end_of_identifier = true;
    return nullptr;
}
auto identifier_recognition::handle(const digit& _e) -> state* {
    return handle(fsm::event(_e));
}
auto identifier_recognition::handle(const alpha& _e) -> state* {
    return handle(fsm::event(_e));
}
auto identifier_recognition::transit(state* const _s) const -> state* {
    if (_end_of_identifier) return nullptr;
    return _s;
}
auto identifier_recognition::clone(const state* const _s) -> state* {
    const auto* const _p = dynamic_cast<const identifier_recognition* const>(_s);
    assert(_p != nullptr);
    if (this != _s && _p != nullptr) *this = *_p;
    return this;
}

namespace __identifier__ {

auto A::entry() -> void {
    _length = 0;
}
auto A::handle(const alpha& _e) -> state* {
    ++_length;
    return fsm::state::instance<B>()->clone(this);
}
auto B::handle(const alpha& _e) -> state* {
    ++_length;
    return fsm::state::instance<B>()->clone(this);
}
auto B::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<B>()->clone(this);
}

}

}}}