#include "syntax/abstract_syntax_tree.hpp"
#include "syntax/cfg/definition.hpp"

#include <iostream>

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
auto node::shrink() -> void {
    std::ignore = _M_remove_epsilon();
    _M_shorten();
}
auto node::_M_remove_epsilon() -> bool {
    if (_syntax->begin() == _syntax->end()) { // epsilon
        clear();
        return true;
    }
    for (auto _i = children().size(); _i != 0; --_i) {
        auto* const _child = children()[_i - 1];
        if (_child->_M_remove_epsilon()) {
            pop();
        }
    }
    return false;
}
auto node::_M_shorten() -> void {
    if (children().empty()) return;
    for (auto* const _child : children()) {
        _child->_M_shorten();
    }
    if (children().size() == 1) {
        auto* const _child = children()[0];
        children() = _child->children();
        _child->children().clear();
    }
}



void print_node(const node* const _root, size_t _depth) {
    const std::string _prefix = "   |";
    for (size_t _i = 0; _i != _depth; ++_i) {
        std::cout << _prefix;
    }
    std::cout << " - ";
    std::cout << _root->syntax()->label() << " : ";
    for (auto _i = _root->syntax()->begin(); _i != _root->syntax()->end(); ++_i) {
        std::cout << _i->attribute_value() << ' ';
    }
    std::cout << std::endl;
    for (const auto* const _child : _root->children()) {
        print_node(_child, _depth + 1);
    }
}

}

}