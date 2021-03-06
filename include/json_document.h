#ifndef JSON_DOCUMENT_H
#define JSON_DOCUMENT_H

#include "token_parser.h"

PARSER_BEGIN_NAMESPACE

class json_object;
class json_array;
class json_value;
class json_document : public token_parser
{
    static int token(int n);
    json_value *_root;

public:
    json_document();
    json_document(json_array *root);
    json_document(json_object *root);

    std::string to_string(print_type type = print_type::compact) const;
    json_value *find(const std::string &path);

    bool is_array() const;
    bool is_object() const;
    json_object *to_object();
    json_array *to_array();

protected:
    void parse();

private:
    void init();
    json_value *parse_value();
    json_value *parse_value(const std::string &token);
    json_object *parse_object();
    json_array *parse_array();
};

PARSER_END_NAMESPACE

#endif // JSON_DOCUMENT_H
