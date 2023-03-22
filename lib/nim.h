#pragma once
#include<iostream>
#include<vector>

class Nim {
    std::vector<int> rows {1, 3, 5};
    std::vector<std::pair<int ,int>> possible_moves {};
    std::string elem = "|";
public:
    bool is_move_correct(std::pair<int, int> m);
    bool make_move(std::pair<int, int> m);
    std::string get_elem() const;
    std::vector<int> get_rows() const;
    void set_rows(std::vector<int> v);
    bool game_finished();
    void gen_possible_moves();
    std::vector<std::pair<int ,int>> get_possible_moves();
    std::pair<int, int> get_best_move();
    //almost same function as in UI, temporarily defined here for testing purposes
    void print();
};
