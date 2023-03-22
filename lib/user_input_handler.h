#pragma once
#include<iostream>
#include<vector>

class UserInputHandler {
public:
    std::string ask_name();
    std::vector<int> ask_heaps_nim();
    std::vector<int> ask_heaps_chomp();
    std::pair<int, int> ask_move();
    int ask_mode();
    int ask_game();
    int ask_starts_first();
};