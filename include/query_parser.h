#ifndef QUERY_PARSER_H
#define QUERY_PARSER_H

#include "token_parser.h"

#include <string>
#include <vector>

class html_tag;
class query_parser : public token_parser
{
    struct query_rule_t{
        std::string id;
        std::string tag_name;
        std::vector<std::string> classes;
        bool is_child;

        bool is_valid() const;
        bool check(html_tag *tag) const;

        query_rule_t();
    };
    std::vector<std::vector<query_rule_t*>> rules;

public:
    query_parser();

    // token_parser interface
public:
    void parse();
    html_tag *tag;
    std::vector<html_tag*> search();
    void search(std::vector<html_tag*> *tags, html_tag *tag,
                size_t rule_id,
                std::vector<query_rule_t *> rules);
private:
    static int token(int n);
};

#endif // QUERY_PARSER_H
