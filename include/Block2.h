#pragma once
#include "Block.h"


class Block2 : public Block{
    
public:
    Block2(): Block(sf::Color(255,0,255)){
            m_pos.push_back( std::pair<unsigned, unsigned>(4,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(3,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(4,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(5,1) );
    }

    ~Block2(){}

    void rotate( sf::Color** arr )
        { convert(2, arr); }

};
