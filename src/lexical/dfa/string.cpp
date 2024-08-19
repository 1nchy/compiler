#include "lexical/dfa/string.hpp"

namespace icy { namespace lexical { namespace dfa {

auto string_recognition::operator=(const string_recognition& _s)
-> string_recognition& {
    if (&_s == this) return *this;
    _length = _s._length;
    _end_of_string = _s._end_of_string;
    return *this;
}
auto string_recognition::handle(const fsm::event& _e) -> state* {
    _end_of_string = true;
    return nullptr;
}
auto string_recognition::handle(const backslash& _e) -> state* {
    return handle(fsm::event(_e));
}
auto string_recognition::handle(const double_quote& _e) -> state* {
    return handle(fsm::event(_e));
}
auto string_recognition::transit(state* const _s) const -> state* {
    if (_end_of_string) return nullptr;
    return _s;
}
auto string_recognition::clone(const state* const _s) -> state* {
    const auto* const _p = dynamic_cast<const string_recognition* const>(_s);
    assert(_p != nullptr);
    if (this != _s && _p != nullptr) *this = *_p;
    return this;
}

namespace __string__ {

auto A::entry() -> void {
    _length = 0;
}
auto A::handle(const double_quote& _e) -> state* {
    ++_length;
    return fsm::state::instance<BE>()->clone(this);
}
auto BE::handle(const fsm::event& _e) -> state* {
    ++_length;
    return fsm::state::instance<BDE>()->clone(this);
}
auto BE::handle(const backslash& _e) -> state* {
    ++_length;
    return fsm::state::instance<C>()->clone(this);
}
auto BE::handle(const double_quote& _e) -> state* {
    ++_length;
    return fsm::state::instance<F>()->clone(this);
}
auto C::handle(const fsm::event& _e) -> state* {
    ++_length;
    return fsm::state::instance<BDE>()->clone(this);
}
auto BDE::handle(const fsm::event& _e) -> state* {
    ++_length;
    return fsm::state::instance<BDE>()->clone(this);
}
auto BDE::handle(const backslash& _e) -> state* {
    ++_length;
    return fsm::state::instance<C>()->clone(this);
}
auto BDE::handle(const double_quote& _e) -> state* {
    ++_length;
    return fsm::state::instance<F>()->clone(this);
}

}

}}}