#pragma once
#include "Block0.h"
#include "Block1.h"
#include "Block2.h"
#include "Block3.h"
#include "Block4.h"
#include "Block5.h"
#include "Block6.h"
#include <SFML/Window.hpp>
#include <iostream>
#include <string>


// class representing a tetris game. It constructs a board of squares filled with colors.
// Black color means a block can move in this square. 
class Game{

public:
    // constructor creating window and running 'run' function
    Game();
    // destructor that frees previously allocated memory 
    ~Game();

private:
    // array of fields
    sf::Color** arr;
    // flag that informs if next block should be created
    bool next_block = 0;
    // counter telling when a block should go down automatically
    unsigned time_counter = 0;
    // counter preventing a block from moving more than 1 time with only 1 click
    unsigned click_counter = 0;
    // time_counters limit; decreases every time a player gets point
    unsigned max_counter = 300;
    // number of points a player gained
    unsigned points = 0;
    // window that displays a tetris game
    sf::RenderWindow* window;

    // functions that runs a tetris game
    void run();
    // functions that randoms a block type; it returns a pointer to alocated object of class Block0, Block1, ... or Block6 
    Block* rand_block( int );
    // function that clears board
    void clear_board();
    // function that draws background of the game
    void draw_background();
    // draws blocks placed on board
    void draw_blocks();
    // draws current block
    void draw_block( Block* );

};
