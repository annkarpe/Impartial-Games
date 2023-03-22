#pragma once
#include<iostream>
#include<vector>

class Chomp {
    std::vector<int> rows {4, 4, 4};
    std::vector<std::pair<int ,int>> possible_moves {};
    std::string elem = "[ ]";
    std::string spec_elem = "[X]";

public:    
    bool is_move_correct(std::pair<int, int> m);
    bool make_move(std::pair<int, int> m);
    std::vector<int> get_rows() const;  
    std::string get_elem() const;
    std::string get_spec_elem() const;
    void set_rows(std::vector<int> v);
    void gen_possible_moves();
    std::vector<std::pair<int ,int>> get_possible_moves();
    std::pair<int, int> get_best_move();
    bool game_finished();
};
