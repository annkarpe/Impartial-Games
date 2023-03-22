#include<iostream>
#include"../lib/chomp.h"


bool Chomp::is_move_correct(std::pair<int, int> m) {
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
bool Chomp::make_move(std::pair<int, int> m) {
    if (is_move_correct(m)) {
        int max_num = rows[m.first - 1] - m.second;
        for (int i = 0; i <= m.first; i++) {
            int r = rows[i];
            int temp = r - m.second;
            if (temp >= max_num) {
                rows[i] = max_num;
            } else {
                rows[i] -= r - max_num;
            }
        }   
        return true;
    } else {
        std::cout << "Incorrect move\n";
        return false;
    }
}
std::vector<int> Chomp::get_rows() const {
    return rows;
}   
std::string Chomp::get_elem() const {
    return elem;
}
std::string Chomp::get_spec_elem() const {
    return elem;
}

void Chomp::set_rows(std::vector<int> v) {
    rows = v;
}

void Chomp::gen_possible_moves() {
    possible_moves.clear();
    std::vector<int> curr_pos = get_rows();
    std::pair<int, int> move;
    for (int i = 0; i < rows.size(); i++) {
        while(curr_pos[i] != 0) {
            move = {i, curr_pos[i]};
            --curr_pos[i];
            possible_moves.push_back(move);
        }
    }
}

std::vector<std::pair<int ,int>> Chomp::get_possible_moves() {
    return possible_moves;
}
/// ?????????????????????????????????????
std::pair<int, int> Chomp::get_best_move() {
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

    int rand = std::rand() % possible_moves.size();
    return possible_moves[rand];
}

bool Chomp::game_finished() {
    for (auto i : rows) {
        if (i != 0) {
            return false;
        }
    }
    return true;
};

