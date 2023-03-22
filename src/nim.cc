#include<iostream>
#include"../lib/nim.h"

bool Nim::is_move_correct(std::pair<int, int> m) {
    if(m.first > get_rows().size() || m.first < 0) {
        return false;
    }
    int temp = rows[m.first ];
    if (temp - m.second < 0) {
        return false;
    } else if (m.second <= 0) {
        return false;
    }
    return true;
}

bool Nim::make_move(std::pair<int, int> m) {
    if (is_move_correct(m)) {
        rows[m.first] = rows[m.first] - m.second;
        return true;
    } else {
        std::cout << "Incorrect move\n";
        return false;
    }
}
std::string Nim::get_elem() const {
    return elem;
}
std::vector<int> Nim::get_rows() const {
    return rows;
};

void Nim::set_rows(std::vector<int> v) {
    rows = v;
}
bool Nim::game_finished() {
    for (auto i : rows) {
        if (i != 0) {
            return false;
        }
    }
    return true;
};

void Nim::gen_possible_moves() {
    possible_moves.clear();
    std::vector<int> curr_pos = get_rows();
    std::pair<int, int> move;
    for (int i = 0; i <= rows.size(); i++) {
        while(curr_pos[i] != 0) {
            move = {i, curr_pos[i]};
            --curr_pos[i];
            possible_moves.push_back(move);
        }
    }
};

std::vector<std::pair<int ,int>> Nim::get_possible_moves() {
    return possible_moves;
}

std::pair<int, int> Nim::get_best_move() {
    std::vector<int> curr_rows = get_rows();
    std::vector<int> rows_after_move = curr_rows;
    for (int i = 0; i < possible_moves.size(); i++) {
        int row_chosen = possible_moves[i].first;
        int elems_remove = possible_moves[i].second;
        for (int j = 0; j < row_chosen; j++) {
            rows_after_move[j] = rows[j];
        }
        rows_after_move[row_chosen] = curr_rows[row_chosen] - elems_remove;

        for (int j = row_chosen + 1; j < curr_rows.size(); j++) {
            rows_after_move[j] = rows[j];
        }
        int res = 0;
        for (int i = 0; i < rows_after_move.size(); i++) {
            res = res ^ rows_after_move[i];  
        }
        if (res == 0) {
            return std::pair<int, int> {possible_moves[i].first, possible_moves[i].second};
        }
    }
    
    /* it's more concise, but does not work
    for (auto m : possible_moves) {
        int row_chosen = m.first;
        int elems_remove = m.second;
        //something is wrong here
        rows_after_move[row_chosen] = curr_rows[row_chosen] - elems_remove;
        int res = 0;
        for (int i = 0; i < rows_after_move.size(); i++) {
            res = res ^ rows_after_move[i];  
        }
        if (res == 0) {
            return m;
        }
    }*/
    int rand = std::rand() % possible_moves.size();
    return possible_moves[rand];
};

void Nim::print() {
    std::string elem = get_elem();
    std::string spec_elem;
    spec_elem = elem;
    int i = 0;
    for (i; i < rows.size(); i++) {
        std::cout << "Row: " << i << ":";
        for (int j = 0; j < rows[i]; j++) {
            std::cout << elem;
        }
        std::cout << '\n';
    }
    std::cout << spec_elem;
    for (int j = 1; j < rows[i-1]; j++) {
        std::cout << elem;
    }
}

