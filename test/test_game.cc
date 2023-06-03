#include<gtest/gtest.h>
#include"../lib/game.h"
#include"../lib/play.h"

TEST(StringToVec, ReturnsCorrectVector) {
    std::vector<size_t> v {1, 3, 5};
    EXPECT_EQ(v, string_to_vec("1 3 5"));
}


class NimTest : public testing::Test {
public:
    Nim n;
};

TEST_F(NimTest, AnyMovesLeftReturnsFalseWhenThereAreNoTokensInHeaps) {
    n.from_string("0 0 0");
    ASSERT_FALSE(n.any_moves_left());
}

TEST_F(NimTest, AnyMovesLeftReturnsTrueWhenThereAreTokensInHeaps) {
    n.from_string("0 4 0");
    ASSERT_TRUE(n.any_moves_left());
}

TEST_F(NimTest, ToStringReturnsCorrectBoardPosition) {
    n.from_string("0 2 2");
    std::string s = "0: \n1: ||\n2: ||\n";
    ASSERT_EQ(s, n.to_string());
}

TEST_F(NimTest, MoveReturnsFalseWhenStringOfSizeNotTwoPassedAsParam) {
    ASSERT_FALSE(n.move("4 3 0"));
    ASSERT_FALSE(n.move("5"));
}

TEST_F(NimTest, MoveReturnsFalseWhenIncorectIndexOfHeapPassed) {
    n.from_string("1 2");
    ASSERT_FALSE(n.move("2 3"));
}

TEST_F(NimTest, MoveReturnsFalseWhenTakenMoreTokensThenInHeap) {
    n.from_string("4 2");
    ASSERT_FALSE(n.move("1 3"));
}

TEST_F(NimTest, MoveReturnsFalseWhenZeroTokensTaken) {
    n.from_string("3 3");
    ASSERT_FALSE(n.move("1 0"));
}

TEST_F(NimTest, MoveReturnsTrueWhenCorrectMove) {
    n.from_string("4 5 6");
    ASSERT_TRUE(n.move("2 3"));
}

TEST_F(NimTest, ToStringReturnsCorrectBoardPositionAfterMove) {
    n.from_string("4 1 3");
    n.move("0 4");
    std::string s = "0: \n1: |\n2: |||\n";
    ASSERT_EQ(s, n.to_string());
}

class ChompTest : public testing::Test {
public:
    Chomp ch;
};

TEST_F(ChompTest, AnyMovesLeftReturnsTrueWhenThereAreTokensInRows) {
    ch.from_string("1 6 7");
    ASSERT_TRUE(ch.any_moves_left());
}

TEST_F(ChompTest, AnyMovesLeftReturnsTrueWhenThereAreNoTokensInRows) {
    ch.from_string("0 0");
    ASSERT_FALSE(ch.any_moves_left());
}

TEST_F(ChompTest, ToStringReturnsCorrectBoardPosition) {
    ch.from_string("3 5 7"); 
    std::string s = "0: [ ][ ][ ]\n1: [ ][ ][ ][ ][ ]\n2: [x][ ][ ][ ][ ][ ][ ]\n";
    ASSERT_EQ(s, ch.to_string());
}

TEST_F(ChompTest, MoveReturnsFalseWhenStringOfSizeNotTwoPassedAsParam) {
    ASSERT_FALSE(ch.move("2 3 4"));
    ASSERT_FALSE(ch.move("1"));
}

TEST_F(ChompTest, MoveReturnsFalseWhenIncorectIndexOfRowPassed) {
    ch.from_string("5");
    ASSERT_FALSE(ch.move("1 2"));
}

TEST_F(ChompTest, MoveReturnsFalseWhenTakenMoreTokensThenInRow) {
    ch.from_string("3 3");
    ASSERT_FALSE(ch.move("1 4"));
}

TEST_F(ChompTest, MoveReturnsFalseWhenZeroTokensTaken) {
    ch.from_string("1 3");
    ASSERT_FALSE(ch.move("1 0"));
}

TEST_F(ChompTest, MoveReturnsTrueWhenCorrectMove) {
    ch.from_string("4 4 4 4");
    ASSERT_TRUE(ch.move("1 4"));
}

TEST_F(ChompTest, ToStringReturnsCorrectBoardPositionAfterMove) {
    ch.from_string("4 4 4");
    ch.move("1 1");
    std::string s = "0: [ ][ ][ ]\n1: [ ][ ][ ]\n2: [x][ ][ ][ ]\n";
    ASSERT_EQ(s, ch.to_string());
}


