#pragma once
#include "Block.h"


class Block1 : public Block{
    
public:
    Block1(): Block(sf::Color::Blue){
            m_pos.push_back( std::pair<unsigned, unsigned>(3,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(3,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(4,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(5,1) );
    }

    ~Block1(){}

    void rotate( sf::Color** arr )
        { convert(2, arr); }

};
