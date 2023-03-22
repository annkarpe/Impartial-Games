#include<gtest/gtest.h>
#include"impartial_game.h"
#include"player.h"

class ImpartialGameTest : public testing::Test {
public:
    ImpartialGame ig;
};

TEST_F(ImpartialGameTest, SetChosenGameReturnsFalseWhenIncorrectInput) {
    ASSERT_FALSE(ig.set_chosen_game(-1));
}

TEST_F(ImpartialGameTest, SetChosenGameReturnsTrueWhenCorrectInput) {
    ASSERT_TRUE(ig.set_chosen_game(1));
    ASSERT_TRUE(ig.set_chosen_game(0));
}

TEST_F(ImpartialGameTest, SetChosenGameSetsNimWhenInputIs0) {
    ig.set_chosen_game(0);
    ASSERT_EQ(ig.get_chosen_game(), ChosenGame::N);
}

TEST_F(ImpartialGameTest, SetChosenGameSetsChompWhenInputIs1) {
    ig.set_chosen_game(1);
    ASSERT_EQ(ig.get_chosen_game(), ChosenGame::Ch);
}

TEST_F(ImpartialGameTest, SetStartsFirstReturnsFalseWhenIncorrectInput) {
    ASSERT_FALSE(ig.set_starts_first(3));
}

TEST_F(ImpartialGameTest, SetStartsFirstSetsPlayerWhenInputIs0) {
    ig.set_starts_first(0);
    ASSERT_EQ(ig.get_starts_first(), StartsFirst::P);
}

TEST_F(ImpartialGameTest, SetStartsFirstSetsComputerWhenInputIs1) {
    ig.set_starts_first(1);
    ASSERT_EQ(ig.get_starts_first(), StartsFirst::C);
}

TEST_F(ImpartialGameTest, SetModeReturnsFalseWhenIncorrectInput) {
    ASSERT_FALSE(ig.set_mode(2));
}

TEST_F(ImpartialGameTest, SetModeSetsPPWhenInputIs0) {
    ig.set_mode(0);
    ASSERT_EQ(ig.get_mode(), Mode::PP);
}

TEST_F(ImpartialGameTest, SetModeSetsPCWhenInputIs1) {
    ig.set_mode(1);
    ASSERT_EQ(ig.get_mode(), Mode::PC);
}


