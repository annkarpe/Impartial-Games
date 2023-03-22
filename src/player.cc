#include<iostream>
#include"../lib/player.h"

std::string Player::get_name() const {
    return name;
};
void Player::set_name(std::string n) {
    name = n;
};
