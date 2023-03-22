#pragma once
#include<iostream>

class Player {
    std::string name;
public:
    std::string get_name() const;
    void set_name(std::string n);
};

