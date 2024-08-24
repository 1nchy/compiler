#ifndef _ICY_SYNTAX_AST_HPP_
#define _ICY_SYNTAX_AST_HPP_

#include <vector>

// #include "syntax/cfg/definition.hpp"

namespace icy {

namespace syntax {

struct tree;
struct node;
namespace cfg {
struct virtual_syntax;
}

struct tree {
    tree() = default;
    tree(const tree&) = delete;
    tree(tree&&);
    tree& operator=(const tree&) = delete;
    tree& operator=(tree&&);
    ~tree();
};

struct node {
    node(const cfg::virtual_syntax* const);
    node(const node&) = delete;
    node& operator=(const node&) = delete;
    ~node();
    const node* parent() const;
    node* parent();
    const std::vector<node*>& children() const;
    std::vector<node*>& children();
    const cfg::virtual_syntax* syntax() const;
    void push(const cfg::virtual_syntax* const);
    void pop();
    void clear();
    void shrink();
private:
    bool _M_remove_epsilon();
    void _M_shorten();
private:
    const cfg::virtual_syntax* const _syntax;
    node* _parent = nullptr;
    std::vector<node*> _children;
};

void print_node(const node* const _root, size_t _depth = 0);

}

}

#endif // _ICY_SYNTAX_AST_HPP_