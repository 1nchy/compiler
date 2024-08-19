#include "lexical/dfa/float.hpp"

namespace icy { namespace lexical{ namespace dfa {

auto float_recognition::operator=(const float_recognition& _s)
-> float_recognition& {
    if (&_s == this) return *this;
    _length = _s._length;
    _end_of_float = _s._end_of_float;
    return *this;
}
auto float_recognition::handle(const fsm::event& _e) -> state* {
    _end_of_float = true;
    return nullptr;
}
auto float_recognition::handle(const digit& _e) -> state* {
    return handle(fsm::event(_e));
}
auto float_recognition::handle(const alpha& _e) -> state* {
    return handle(fsm::event(_e));
}
auto float_recognition::handle(const plus& _e) -> state* {
    return handle(fsm::event(_e));
}
auto float_recognition::handle(const minus& _e) -> state* {
    return handle(fsm::event(_e));
}
auto float_recognition::handle(const dot& _e) -> state* {
    return handle(fsm::event(_e));
}
auto float_recognition::transit(state* const _s) const -> state* {
    if (_end_of_float) return nullptr;
    return _s;
}
auto float_recognition::clone(const state* const _s) -> state* {
    const auto* const _p = dynamic_cast<const float_recognition* const>(_s);
    assert(_p != nullptr);
    if (this != _s && _p != nullptr) *this = *_p;
    return this;
}

namespace __float__ {

auto A::entry() -> void {
    _length = 0;
}
auto A::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<ABEI>()->clone(this);
}
auto ABEI::handle(const alpha& _e) -> state* {
    if (_e._c != 'e') {
        _end_of_float = true;
        return nullptr;
    }
    ++_length;
    return fsm::state::instance<FG>()->clone(this);
}
auto ABEI::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<ABEI>()->clone(this);
}
auto ABEI::handle(const dot& _e) -> state* {
    ++_length;
    return fsm::state::instance<C>()->clone(this);
}
auto C::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<CDEI>()->clone(this);
}
auto CDEI::handle(const alpha& _e) -> state* {
    if (_e._c != 'e') {
        _end_of_float = true;
        return nullptr;
    }
    ++_length;
    return fsm::state::instance<CDEI>()->clone(this);
}
auto CDEI::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<CDEI>()->clone(this);
}
auto FG::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<GHI>()->clone(this);
}
auto FG::handle(const plus& _e) -> state* {
    ++_length;
    return fsm::state::instance<GHI>()->clone(this);
}
auto FG::handle(const minus& _e) -> state* {
    ++_length;
    return fsm::state::instance<GHI>()->clone(this);
}
auto G::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<GHI>()->clone(this);
}
auto GHI::handle(const digit& _e) -> state* {
    ++_length;
    return fsm::state::instance<GHI>()->clone(this);
}

}

}}}