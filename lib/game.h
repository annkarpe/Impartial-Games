#ifndef GAME
#define GAME

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>

class Game {
protected:

public:
    std::shared_ptr<std::map<std::string, bool>> transposition_table;

    virtual ~Game() = 0;
    virtual void from_string(const std::string &desc) = 0;
    virtual std::string to_string() const = 0;
    virtual std::vector<std::unique_ptr<Game>> children(
        std::shared_ptr<std::map <std::string, bool>> t_table) const = 0;
    virtual bool move(const std::string &desc) = 0;
    virtual std::string help() const = 0;
    virtual bool any_moves_left() const = 0;
    virtual bool is_winning_pos() = 0;
    virtual bool is_in_table(const std::string &pos) const = 0;
    virtual void add_to_table(const std::string &pos, bool b_val) = 0;
};

std::vector<size_t> string_to_vec(const std::string &s);

class Nim : public Game {
    std::vector<size_t> heaps;
public:
    ~Nim();

    void from_string(const std::string &desc) override;
    std::vector<std::unique_ptr<Game>> children(
        std::shared_ptr<std::map <std::string, bool>> t_table) const override;
    std::string to_string() const override;
    bool move(const std::string &desc) override;
    std::string help() const override;
    bool any_moves_left() const override;
    bool is_winning_pos() override;
    bool is_in_table(const std::string &pos) const;
    void add_to_table(const std::string &pos, bool b_val);

    static std::unique_ptr<Game> create();
};
class Chomp : public Game {
    std::vector<size_t> board;
public:
    ~Chomp();

    void from_string(const std::string &desc) override;
    std::vector<std::unique_ptr<Game>> children(
        std::shared_ptr<std::map <std::string, bool>> t_table) const override;
    std::string to_string() const override;
    bool move(const std::string &desc) override;
    std::string help() const override;
    bool any_moves_left() const override;
    bool is_winning_pos() override;
    bool is_in_table(const std::string &pos) const;
    void add_to_table(const std::string &pos, bool b_val);
    static std::unique_ptr<Game> create();
};

#endif
