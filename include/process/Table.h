//
// Created by nrx on 01.06.2020.
//

#ifndef DUMMY_PARSER_TABLE_H
#define DUMMY_PARSER_TABLE_H

class Table {
public:
    Table(const Graph<std::shared_ptr<Token>, Empty> &g);
    const std::vector<std::shared_ptr<Token>>& intConsts();
    const std::vector<std::shared_ptr<Token>>& charConsts();
    const std::vector<std::shared_ptr<Function>>& functions();
    const std::vector<std::shared_ptr<Class>>& classes();
private:
    std::vector<std::shared_ptr<Token>> _intConsts;
    std::vector<std::shared_ptr<Token>> _charConsts;
    std::vector<std::shared_ptr<Function>> _functions();
    std::vector<std::shared_ptr<Class>> _classes;
};


#endif //DUMMY_PARSER_TABLE_H
