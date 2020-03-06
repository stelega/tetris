#pragma once
#include "Block.h"


class Block3 : public Block{
    
public:
    Block3(): Block(sf::Color(255,99,71)){
            m_pos.push_back( std::pair<unsigned, unsigned>(5,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(3,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(4,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(5,1) );
    }

    ~Block3(){}

    void rotate( sf::Color** arr )
        { convert(2, arr); }

};
