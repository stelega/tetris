#pragma once
#include "Block.h"


class Block5 : public Block{
    
public:
    Block5(): Block(sf::Color::Red){
            m_pos.push_back( std::pair<unsigned, unsigned>(3,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(4,0) );
            m_pos.push_back( std::pair<unsigned, unsigned>(4,1) );
            m_pos.push_back( std::pair<unsigned, unsigned>(5,1) );
    }

    ~Block5(){}

    void rotate( sf::Color** arr )
        { convert(2, arr); }

};
