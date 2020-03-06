#pragma once
#include <SFML/Graphics.hpp>


// abstract class made to be a base class for classes Block0, Block1, ... , Block6.
// Those blocks represent blocks that can appear during a game.
class Block{

public:
    // constructor assigning a color to 'm_color' depending on blocks type
    Block(sf::Color);
    // virtual destructor
    virtual ~Block()=0;

    // function moving a block down if possible
    void down();
    // function rotating a block if possible
    void up();
    // function moving a block up if possible
    void left();
    // function moving a block right if possible
    void right();
    // function rotating a block if possible
    virtual void rotate(sf::Color**);
    // fucntion returning color of a block
    sf::Color get_color();
    // operator[] returning element 'i' of 'm_pos' vector 
    std::pair<int, int> operator[](int i);

protected:
    // color of block
    const sf::Color m_color;
    // every block consists of 4 squares placed on game board.
    // 'm_pos' is a vector of int paires representing position(coordinates) of block.
    std::vector<std::pair<int, int>> m_pos;

    // function that checks if a rotation of a block is allowed. 
    // Function rotate a block relative to one of 4 squares depending on first argument.
    void convert(unsigned, sf::Color**);

};