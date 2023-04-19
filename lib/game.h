#ifndef GAME
#define GAME

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>

class Game {
public:
    virtual ~Game() = 0;
    virtual void from_string(const std::string &desc) = 0;
    virtual std::string to_string() const = 0;
    virtual std::vector<std::unique_ptr<Game>> children() const = 0;
    virtual bool move(const std::string &desc) = 0;
    virtual std::string help() const = 0;
    virtual bool any_moves_left() const = 0;
    virtual bool is_winning_pos() const = 0;
};

std::vector<size_t> string_to_vec(const std::string &s);

class Nim : public Game {
    std::vector<size_t> heaps;
    std::map <std::string, bool> transposition_table;
public:
    ~Nim();

    void from_string(const std::string &desc) override;
    std::vector<std::unique_ptr<Game>> children() const override;
    std::string to_string() const override;
    bool move(const std::string &desc) override;
    std::string help() const override;
    bool any_moves_left() const override;
    bool is_winning_pos() const override;

    static std::unique_ptr<Game> create();
};
class Chomp : public Game {
    std::vector<size_t> board;
    std::map <std::string, bool> transposition_table;
public:
    ~Chomp();

    void from_string(const std::string &desc) override;
    std::vector<std::unique_ptr<Game>> children() const override;
    std::string to_string() const override;
    bool move(const std::string &desc) override;
    std::string help() const override;
    bool any_moves_left() const override;
    bool is_winning_pos() const override;

    static std::unique_ptr<Game> create();
};

#endif
