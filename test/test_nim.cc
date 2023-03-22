#include<gtest/gtest.h>
#include"../lib/nim.h"

class NimTest : public testing::Test {
public:
    Nim nim;
};

TEST_F(NimTest, GameFinishedReturnsTrueWhenAllValInRowsAreZero) {
    nim.set_rows(std::vector{0, 0, 0});
    ASSERT_TRUE(nim.game_finished());
}
TEST_F(NimTest, GameFinishedReturnsFalseRowsContainElements) {
    nim.set_rows(std::vector{3, 0, 8});
    ASSERT_FALSE(nim.game_finished());
}

TEST_F(NimTest, IsMoveCorrectReturnsFalseWhenZeroElementsTaken) {
    ASSERT_FALSE(nim.is_move_correct(std::pair<int, int>{1, 0}));
}

TEST_F(NimTest, IsMoveCorrectReturnsFalseWhenFromNonExistentRowElementsTaken) {
    nim.set_rows(std::vector{2, 3, 2});
    ASSERT_FALSE(nim.is_move_correct(std::pair<int, int>{3, 2}));
    ASSERT_FALSE(nim.is_move_correct(std::pair<int, int>{-1, 2}));
}

TEST_F(NimTest, IsMoveCorrectReturnsFalseWhenFromEmptyRowElementsTaken) {
    nim.set_rows(std::vector{0, 3, 0});
    ASSERT_FALSE(nim.is_move_correct(std::pair<int, int>{2, 2}));
}

TEST_F(NimTest, IsMoveCorrectReturnsFalseWhenTakeMoreElementsThenInRow) {
    nim.set_rows(std::vector{0, 3, 2});
    ASSERT_FALSE(nim.is_move_correct(std::pair<int, int>{2, 6}));
}

TEST_F(NimTest, IsMoveCorrectReturnsTrueWhenMoveIsCorrect) {
    nim.set_rows(std::vector{2, 3, 2});
    ASSERT_TRUE(nim.is_move_correct(std::pair<int, int>{0, 1}));
    ASSERT_TRUE(nim.is_move_correct(std::pair<int, int>{1, 3}));
    ASSERT_TRUE(nim.is_move_correct(std::pair<int, int>{2, 2}));
}

TEST_F(NimTest, CorrectPossibleMovesGenerated) {
    nim.set_rows(std::vector{1, 2});
    nim.gen_possible_moves();
    std::vector<std::pair<int, int>>
         pm {{0, 1}, {1, 2}, {1, 1}};
    ASSERT_EQ(nim.get_possible_moves(), pm);
}

TEST_F(NimTest, MakeMoveRemovesCorrectNumOfElementsFromTheCorrectRow) {
    nim.set_rows(std::vector{2, 3, 2});
    nim.make_move({1, 2});
    std::vector<int> b {2, 1, 2};
    ASSERT_EQ(nim.get_rows(), b);
}
TEST_F(NimTest, GenPossibleMovesGeneratesCorrectMoves) {
    nim.set_rows(std::vector<int>{1, 2});
    nim.gen_possible_moves();
    std::vector<std::pair<int, int>> v = { {0, 1}, {1, 2}, {1, 1}};
    ASSERT_EQ(nim.get_possible_moves(), v);
}
TEST_F(NimTest, GenPossibleMovesGeneratesCorrectMovesForBoard3x3) {
    nim.set_rows(std::vector<int>{3, 3, 3});
    nim.gen_possible_moves();
    std::vector<std::pair<int, int>> v = { {0, 3}, {0, 2}, {0, 1}, 
        {1, 3}, {1, 2}, {1, 1}, {2, 3}, {2, 2}, {2, 1}};
    ASSERT_EQ(nim.get_possible_moves(), v);
}

TEST_F(NimTest, GetBestMoveReturnsBestMove) {
    nim.set_rows(std::vector<int>{3, 5});
    nim.gen_possible_moves();
    std::pair<int, int> v{1, 2};
    ASSERT_EQ(nim.get_best_move(), v);
}