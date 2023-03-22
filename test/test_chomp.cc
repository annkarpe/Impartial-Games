#include<gtest/gtest.h>
#include"chomp.h"

class ChompTest : public testing::Test {
public:
    Chomp chomp;
};

//*****Tests, which are common both for nim and chomp*****
TEST_F(ChompTest, GameFinishedReturnsTrueWhenAllValInRowsAreZero) {
    chomp.set_rows(std::vector{0, 0, 0});
    ASSERT_TRUE(chomp.game_finished());
}

TEST_F(ChompTest, GameFinishedReturnsFalseRowsContainElements) {
    chomp.set_rows(std::vector{3, 0, 8});
    ASSERT_FALSE(chomp.game_finished());
}

TEST_F(ChompTest, IsMoveCorrectReturnsFalseWhenZeroElementsTaken) {
    ASSERT_FALSE(chomp.is_move_correct(std::pair<int, int>{1, 0}));
}

TEST_F(ChompTest, IsMoveCorrectReturnsFalseWhenFromNonExistentRowElementsTaken) {
    chomp.set_rows(std::vector{3, 3, 3});
    ASSERT_FALSE(chomp.is_move_correct(std::pair<int, int>{3, 2}));
    ASSERT_FALSE(chomp.is_move_correct(std::pair<int, int>{-1, 2}));
}

TEST_F(ChompTest, IsMoveCorrectReturnsFalseWhenFromEmptyRowElementsTaken) {
    chomp.set_rows(std::vector{0, 0, 3});
    ASSERT_FALSE(chomp.is_move_correct(std::pair<int, int>{1, 2}));
}

TEST_F(ChompTest, IsMoveCorrectReturnsFalseWhenTakeMoreElementsThenInRow) {
    chomp.set_rows(std::vector{0, 2, 2});
    ASSERT_FALSE(chomp.is_move_correct(std::pair<int, int>{2, 6}));
}

TEST_F(ChompTest, IsMoveCorrectReturnsTrueWhenMoveIsCorrect) {
    chomp.set_rows(std::vector{3, 3, 3});
    ASSERT_TRUE(chomp.is_move_correct(std::pair<int, int>{0, 1}));
    ASSERT_TRUE(chomp.is_move_correct(std::pair<int, int>{1, 3}));
    ASSERT_TRUE(chomp.is_move_correct(std::pair<int, int>{2, 2}));
}

TEST_F(ChompTest, CorrectPossibleMovesGeneratedWithBoard2x2) {
    chomp.set_rows(std::vector{2, 2});
    chomp.gen_possible_moves();
    std::vector<std::pair<int, int>>
         pm {{0, 2}, {0, 1}, {1, 2}, {1, 1}};
    ASSERT_EQ(chomp.get_possible_moves(), pm);
}
TEST_F(ChompTest, CorrectPossibleMovesGeneratedWithBoard3x3) {
    chomp.set_rows(std::vector{3, 3, 3});
    chomp.gen_possible_moves();
    std::vector<std::pair<int, int>>
         pm {{0, 3}, {0, 2}, {0, 1}, {1, 3}, {1, 2}, {1, 1}, {2, 3}, {2, 2}, {2, 1}};
    ASSERT_EQ(chomp.get_possible_moves(), pm);
}


TEST_F(ChompTest, GetBestMoveReturnsBestMove) {
    chomp.set_rows(std::vector<int>{3, 5});
    chomp.gen_possible_moves();
    std::pair<int, int> v{1, 2};
    ASSERT_EQ(chomp.get_best_move(), v);
}

// ***tests, which check the features of chomp***
TEST_F(ChompTest, MakeMoveRemovesCorrectNumOfElementsFromTheCorrectRowsV1) {
    chomp.set_rows(std::vector{3, 3, 3});
    //{from_which_row, how_many_els_to_take}
    chomp.make_move({2, 2});
    std::vector<int> b {1, 1, 1};
    ASSERT_EQ(chomp.get_rows(), b);
}
TEST_F(ChompTest, MakeMoveRemovesCorrectNumOfElementsFromTheCorrectRowsV2) {
    chomp.set_rows(std::vector{3, 3, 3});
    chomp.make_move({1, 3});
    std::vector<int> b {0, 0, 3};
    ASSERT_EQ(chomp.get_rows(), b);
}
