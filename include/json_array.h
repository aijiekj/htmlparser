#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include "global.h"
#include "json_value.h"
#include <vector>

PARSER_BEGIN_NAMESPACE

class json_array : public json_value
{
    std::vector<json_value*> _values;

public:
    json_array();
    virtual ~json_array();
    void add(json_value *v);
    json_value *at(const size_t &pos) const;

    const json_value *operator[](const size_t &i) const;
    json_value *operator[](const size_t &i);

private:
    void render(string_renderer &r) override;
};

PARSER_END_NAMESPACE

#endif // JSON_ARRAY_H
