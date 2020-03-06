#pragma once
#include "Block.h"


class Block6 : public Block{
    
public:
    Block6(): Block(sf::Color::Green){
            m_pos.push_back( std::pair<unsigned, unsigned>(4,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(5,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(3,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(4,1) );
    }

    ~Block6(){}

    void rotate( sf::Color** arr )
        { convert(3, arr); }

};
