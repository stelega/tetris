#pragma once
#include "Block.h"


class Block4 : public Block{
    
public:
    Block4(): Block(sf::Color::Yellow){
            m_pos.push_back( std::pair<unsigned, unsigned>(4,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(5,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(4,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(5,1) );
    }

    ~Block4( ){}

};
