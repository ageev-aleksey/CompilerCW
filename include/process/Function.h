//
// Created by nrx on 01.06.2020.
//

#ifndef DUMMY_PARSER_FUNCTION_H
#define DUMMY_PARSER_FUNCTION_H
struct Arg {
    std::string name;
    std::string defaultValue;
};


class Function {
public:
    Function(Graph<std::shared_ptr<Token, Empty>>::iterator node);
    const std::vector<Arg>& getArgs();
    const std::string& getId();
    const Graph<std::shared_ptr<Token, Empty>>::iterator& getBody();

private:
    std::vector<Arg> args;
    Graph<std::shared_ptr<Token, Empty>>::iterator bodyNode;
};

#endif //DUMMY_PARSER_FUNCTION_H
