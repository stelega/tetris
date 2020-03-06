#pragma once
#include "Block.h"


class Block0 : public Block{
    
public:
    Block0(): Block(sf::Color(0,255,255)){
            m_pos.push_back( std::pair<unsigned, unsigned>(3,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(4,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(5,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(6,0) );
    }

    ~Block0(){}

    void rotate( sf::Color** arr )
        { convert(2, arr); }

};
