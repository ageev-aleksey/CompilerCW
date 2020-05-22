//
// Created by nrx on 22.05.2020.
//

#ifndef DUMMY_PARSER_TOKENINFO_H
#define DUMMY_PARSER_TOKENINFO_H

class TokenInfo {
public:
    TokenInfo(const std::string &type_str);
    const std::string& getType() const;
    const std::string& strValue() const;

protected:
    std::string type;
    std::string value;
};


#endif //DUMMY_PARSER_TOKENINFO_H
