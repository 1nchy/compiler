#include "syntax/abstract_syntax_tree.hpp"
#include "syntax/cfg/definition.hpp"

namespace icy {

namespace syntax {



node::node(const cfg::virtual_syntax* const _s) : _syntax(_s) {}
node::~node() {
    clear();
    delete _syntax;
}
auto node::parent() const -> const node* { return _parent; }
auto node::parent() -> node* { return _parent; }
auto node::children() const -> const std::vector<node*>& { return _children; }
auto node::children() -> std::vector<node*>& { return _children; }
auto node::syntax() const -> const cfg::virtual_syntax* { return _syntax; }
auto node::push(const cfg::virtual_syntax* const _s) -> void {
    node* const _n = new node(_s);
    _n->_parent = this;
    _children.push_back(_n);
}
auto node::pop() -> void {
    if (!_children.empty()) {
        delete _children.back();
    }
    _children.pop_back();
}
auto node::clear() -> void {
    for (auto* const _child : _children) {
        delete _child;
    }
    _children.clear();
}

}

}