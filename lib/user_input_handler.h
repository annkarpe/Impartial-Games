#ifndef UIH
#define UIH

#include<iostream>
#include<vector>

class UserInputHandler {
public:
    std::string ask_game() const;
    std::string ask_init() const;
    std::string ask_mode() const;
    std::string ask_starts_first() const;
};


#endif