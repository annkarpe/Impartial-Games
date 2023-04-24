#include"../lib/game.h"
#include"../lib/play.h"
#include<string>
#include<algorithm>

std::vector<size_t> string_to_vec(const std::string &s) {
    std::vector<size_t> ret;
    std::istringstream is(s);

    size_t r;
    while(is >> r) {
        ret.push_back(r);
    }

    return ret;
}

Game::~Game()  { }

Nim::~Nim() { }

void Nim::from_string(const std::string &desc) {
    heaps = string_to_vec(desc);
    transposition_table = std::make_shared<std::map<std::string, bool>>();
    (*transposition_table)[desc] = is_winning_pos();
}

bool Nim::any_moves_left() const {
    return std::any_of(heaps.begin(), heaps.end(), [&](int h) { return h > 0; });
}

std::vector<std::unique_ptr<Game>> Nim::children(
 std::shared_ptr<std::map <std::string, bool>> t_table) const {
    std::vector<std::unique_ptr<Game>> child;
    for ( size_t heap = 0 ; heap < heaps.size() ; heap++) {
        for (size_t h = 1 ; h <= heaps[heap] ; h++) {
            std::unique_ptr<Nim> ptr = std::make_unique<Nim>(*this);
            ptr->heaps[heap] -= h;
            ptr->transposition_table = t_table;
            child.push_back(std::move(ptr));
        }
    }

    return child;
}

bool Nim::is_winning_pos() {
    if (!any_moves_left()) {
        return false;
    }

    std::string pos = to_string();

    if (is_in_table(pos)) {
        return (*transposition_table)[pos];
    }

    auto ch = children(transposition_table);

    for (auto &c: ch) {
        if (!c->is_winning_pos()) {
            add_to_table(pos, true);
            return true;
        } 
    } 
    add_to_table(pos, false);              

    return false;
}

std::string Nim::to_string() const {
    std::string s;
    for ( size_t heap = 0 ; heap < heaps.size() ; heap++) {
        s += std::to_string(heap);
        s += ": ";

        for (size_t h = 0 ; h < heaps[heap] ; h++) {
            s += "|";
        }
        s += "\n";
    }

    return s;
}

bool Nim::move(const std::string &desc) {
    auto m = string_to_vec(desc);

    if (m.size() != 2) {
        return false;
    }

    size_t heap = m[0];

    if (heap >= heaps.size()) {
        return false;
    }

    size_t tokens = m[1];

    if (tokens == 0) {
        return false;
    }

    if (tokens > heaps[heap]) {
        return false;
    }

    heaps[heap] -= tokens;

    return true;
}

std::string Nim::help() const {
    return "please write two numbers, heap id and number of tokens to remove";
}

bool Nim::is_in_table(const std::string &pos) const {
    auto it = transposition_table->find(pos);
    if (it == transposition_table->end()) {
        return false;
    }
    return true;
}

void Nim::add_to_table(const std::string &pos, bool b_val) {
    (*transposition_table)[pos] = b_val;
}

std::unique_ptr<Game> Nim::create() {
    return std::make_unique<Nim>();
}

Chomp::~Chomp() { }

void Chomp::from_string(const std::string &desc) {
    board = string_to_vec(desc);
    transposition_table = std::make_shared<std::map<std::string, bool>>();
    (*transposition_table)[desc] = true;
}

std::vector<std::unique_ptr<Game>> Chomp::children(
 std::shared_ptr<std::map <std::string, bool>> t_table) const {
    std::vector<std::unique_ptr<Game>> child;
    for ( size_t b = 0 ; b < board.size() ; b++) {
        for (size_t h = 1 ; h <= board[b] ; h++) {
            std::unique_ptr<Chomp> ptr = std::make_unique<Chomp>(*this);
            size_t max = ptr->board[b] - h;
            for(int i = 0; i < b; i++) {
                if (ptr->board[i] >= max) {
                    ptr->board[i] = max;
                }
            }
            ptr->board[b] -= h;
            ptr->transposition_table = t_table;
            child.push_back(std::move(ptr));
        }
    }

    return child;
}

bool Chomp::is_winning_pos() {
    if (!any_moves_left()) {
        return false;
    }

    std::string pos = to_string();

    if (is_in_table(pos)) {
        return (*transposition_table)[pos];
    }

    auto ch = children(transposition_table);

    for (auto &c: ch) {
        if (!c->is_winning_pos()) {
            add_to_table(pos, true);
            return true;
        } 
    } 
    add_to_table(pos, false);              

    return false;
}

std::string Chomp::to_string() const {
    std::string s;
    for ( size_t row = 0 ; row < board.size() ; row++) {
        s += std::to_string(row);
        s += ": ";
        for (size_t r = 0 ; r < board[row]; r++) {
            if (row == board.size() - 1 && r == 0) {
                s += "[x]";
            } else {
                s += "[ ]";
            }
        }
        s += "\n";
    }
    return s;
}

bool Chomp::move(const std::string &desc) {
    auto m = string_to_vec(desc);

    if (m.size() != 2) {
        return false;
    }

    size_t row = m[0];

    if (row >= board.size()) {
        return false;
    }

    size_t tokens = m[1];

    if (tokens == 0) {
        return false;
    }

    if (tokens > board[row]) {
        return false;
    }
    size_t max_num = board[row] - tokens;
    for (size_t i = 0; i < row; i++) {
        if(board[i] > max_num) {
            for (size_t j = 0; j < board[i] - max_num; j++) {
                --board[i];
            }
        }
    }
    board[row] -= tokens;

    return true;
}

std::string Chomp::help() const {
    return "please write two numbers, row id and number of tokens to remove";
}

bool Chomp::any_moves_left() const {
    return std::any_of(board.begin(), board.end(), [&](int h) { return h > 0; });
}

bool Chomp::is_in_table(const std::string &pos) const {
    auto it = transposition_table->find(pos);
    if (it == transposition_table->end()) {
        return false;
    }
    return true;
}

void Chomp::add_to_table(const std::string &pos, bool b_val) {
    (*transposition_table)[pos] = b_val;
}

std::unique_ptr<Game> Chomp::create() {
    return std::make_unique<Chomp>();
}