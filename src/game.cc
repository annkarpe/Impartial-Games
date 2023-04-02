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
}

bool Nim::any_moves_left() const {
    return std::any_of(heaps.begin(), heaps.end(), [&](int h) { return h > 0; });
}

std::vector<std::unique_ptr<Game>> Nim::children() const {
    std::vector<std::unique_ptr<Game>> child;
    for ( size_t heap = 0 ; heap < heaps.size() ; heap++) {
        for (size_t h = 1 ; h <= heaps[heap] ; h++) {
            std::unique_ptr<Nim> ptr = std::make_unique<Nim>(*this);
            ptr->heaps[heap] -= h;
            child.push_back(std::move(ptr));
        }
    }

    return child;
}

bool Nim::is_winning_pos() const {
    if (!any_moves_left()) {
        return false;
    }

    auto ch = children();

    for (auto &c: ch) {
        if (!c->is_winning_pos()) {
            return true;
        }
    }

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

std::unique_ptr<Game> Nim::create() {
    return std::make_unique<Nim>();
}

Chomp::~Chomp() { }

void Chomp::from_string(const std::string &desc) {
    board = string_to_vec(desc);
}

std::vector<std::unique_ptr<Game>> Chomp::children() const {
    std::vector<std::unique_ptr<Game>> child;
    for ( size_t b = 0 ; b < board.size() ; b++) {
        for (size_t h = 1 ; h <= board[b] ; h++) {
            std::unique_ptr<Chomp> ptr = std::make_unique<Chomp>(*this);
            ptr->board[b] -= h;
            child.push_back(std::move(ptr));
        }
    }

    return child;
}

bool Chomp::is_winning_pos() const {
    if (!any_moves_left()) {
        return false;
    }

    auto ch = children();

    for (auto &c: ch) {
        if (!c->is_winning_pos()) {
            return true;
        }
    }
    
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
    for (size_t i = 0; i <= row; i++) {
        size_t r = board[i];
        size_t temp = r - tokens;
        if (temp >= max_num) {
            board[i] = max_num;
        } else {
            board[i] -= r - max_num;
        }
    }

    return true;
}

std::string Chomp::help() const {
    return "please write two numbers, row id and number of tokens to remove";
}

bool Chomp::any_moves_left() const {
    return std::any_of(board.begin(), board.end(), [&](int h) { return h > 0; });
}

std::unique_ptr<Game> Chomp::create() {
    return std::make_unique<Chomp>();
}


