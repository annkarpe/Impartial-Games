#ifndef GAME
#define GAME

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

class Game {
public:
    virtual ~Game() = 0;
    virtual void from_string(const std::string &desc) = 0;
    virtual std::string to_string() const = 0;
    virtual std::vector<std::unique_ptr<Game>> children() const = 0;
    virtual bool move(const std::string &desc) = 0;
    virtual std::string help() const = 0;
    virtual bool any_moves_left() const = 0;
};

std::vector<size_t> string_to_vec(const std::string &s);

class Nim : public Game {
    std::vector<size_t> heaps;
public:
    ~Nim();

    void from_string(const std::string &desc) override;
    std::vector<std::unique_ptr<Game>> children() const override;
    std::string to_string() const override;
    bool move(const std::string &desc) override;
    std::string help() const override;
    bool any_moves_left() const override;
};


class Chomp : public Game {
    std::vector<size_t> board;
public:
    ~Chomp();

    void from_string(const std::string &desc) override;
    std::vector<std::unique_ptr<Game>> children() const override;
    std::string to_string() const override;
    bool move(const std::string &desc) override;
    std::string help() const override;
    bool any_moves_left() const override;
};
/*
class AI {
    std::unique_ptr<Game> g;
    std::vector<std::pair<size_t, size_t>> possible_moves;
public:
    

};

class NimAI : public AI {

};

class ChompAI : public AI {

}*/

#endif