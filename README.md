# Impartial Games


This repository contains the C++ implementation of two impartial games: Nim and Chomp. Each of the games can be played with either an AI or another player. The games are implemented with the misère play rule. The code is covered with GoogleTest.

## Table of contents
1. Getting Started
2. Game rules
3. Implementation


### Getting Started

#### Instalation 

Clone this repository to your local machine using:
``` bash
git clone https://github.com/annkarpe/Impartial-Games.git
```
#### Running tests
In order to run the tests on a Linux machine you can use these commands:
1. Create a build directory inside a project directory
``` bash
mkdir build
```
2. Configure and generate build files inside 'build' directory
``` bash
cmake -S . -B build
```
3. Read the Makefile generated by CMake and build the project
``` bash
cd build && make
```
4. Run the executable file
``` bash
./imp
```
### Game rules

#### Nim
The game of Nim is represented by several heaps of tokens. Two players take turns removing tokens from the heaps. During one move it's possible to remove tokens only from at most heap. At least one token should be removed during the move. The player, who removes the last token loses (misère play).

#### Chomp
The game of chomp is represented by a rectangular grid of tokens (like a chocolate bar) and as well as in Nim game, two players thake turns removing tokens. On each turn a player must remove a rectangular block of tokens from the grid, at least one element. Unlike the Nim game, all the tokens to the right and above the choosen token are taken. Consequently, the player is allowed to remove tokens from more than one row. The player, who removes the last token loses (misère play). 

### Implementation

The 'Impartial Games' is implemented using the definition of Nim, that any impartial game can is equivalent to a certain game of Nim. 

To enable the easy extension, extendable Factory Pattern was used. It allows not us only to create instances of the 'Game' class but also to register new, derived from the base class impartial games without changing the other code.

The AI algorithm is based on a definition of a game as a set of games. Which in our case implies that each position has a set of legal consequent positions. And the AI selects the one, which leads the oponent to lose the game. 

The AI uses memoization to avoid redundant calculations of whether a given state is a winning or losing position. If the state is new, the algorithm computes whether it is a winning or losing position and stores it in the transposition table, represented by a map. If the state has alredy been encountered, the corresponding boolean value is returned from the table.
