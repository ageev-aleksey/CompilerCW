//
// Created by nrx on 01.06.2020.
//

#ifndef DUMMY_PARSER_CLASS_H
#define DUMMY_PARSER_CLASS_H
#include <vector>
enum class AccessModifier {
    PUBLIC,
    PROTECTED,
    PRIVATE
};

struct Method {
    Function func;
    AccessModifier mod;
};

struct Field {

};

class Class {
private:
    std::vector<Method> methods;
    std::vector<Field> fields;
};

#endif //DUMMY_PARSER_CLASS_H
