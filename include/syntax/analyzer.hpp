#ifndef _ICY_SYNTAX_ANALYZER_HPP_
#define _ICY_SYNTAX_ANALYZER_HPP_

#include <vector>

#include "lexical/lexeme.hpp"
#include "lexical/analyzer.hpp"

namespace icy {

namespace syntax {

class analyzer;

class analyzer {
public:
    analyzer() = default;
    analyzer(const analyzer&) = delete;
    analyzer& operator=(const analyzer&) = delete;
    ~analyzer() = default;
public:
    void scan(const std::vector<lexical::lexeme>&);
};

}

}

#endif // _ICY_SYNTAX_ANALYZER_HPP_