#include "Block.h"
#include "time.h"


Block::Block( sf::Color c ): m_color(c){}


Block::~Block(){}


void Block::down(){
    for( auto &i : m_pos )
        i.second++;
}

void Block::up(){
    for( auto &i : m_pos )
        i.second--;
}

void Block::left(){
    for( auto &i : m_pos )
        i.first--;
}

void Block::right(){
    for( auto &i : m_pos )
        i.first++;
}


void Block::rotate(sf::Color**){}


sf::Color Block::get_color()
    { return m_color; }


std::pair<int, int> Block::operator[](int index)
    { return m_pos[index]; }


void Block::convert(unsigned index, sf::Color** arr){
    bool flag = true;
    // checking if rotation is possible
    for(unsigned i=0; i<4; i++){
        if(i!=index){
            int x = m_pos[i].first - m_pos[index].first;
            int y = m_pos[i].second - m_pos[index].second;
            // depending on a square position relative to rotation center it should change position differently
            if( (x<0 && y<0) || (x>0 && y>0) ){
                if( arr[m_pos[index].first - x + 1][m_pos[index].second + 1] != sf::Color::Black && arr[m_pos[index].first - x + 1][m_pos[index].second + 1] != sf::Color(255,255,128) ){
                    flag = false;
                    break;
                }
            }
            else if( (x>0 && y<0) || (x<0 && y>0) ){
                if( arr[m_pos[index].first + 1][m_pos[index].second -y + 1] != sf::Color::Black && arr[m_pos[index].first + 1][m_pos[index].second - y + 1] != sf::Color(255,255,128) ){
                    flag = false;
                    break;
                }
            
            }
            else if( y==0 ){
                if( arr[m_pos[index].first + 1][m_pos[index].second + x + 1] != sf::Color::Black && arr[m_pos[index].first + 1][m_pos[index].second + x + 1] != sf::Color(255,255,128) ){
                    flag = false;
                    break;
                }

            }
            else if( x==0 ){
                if( arr[m_pos[index].first - y + 1][m_pos[index].second + 1] != sf::Color::Black && arr[m_pos[index].first - y + 1][m_pos[index].second + 1] != sf::Color(255,255,128) ){
                    flag = false;
                    break;
                }
            }
        }
    }

    // if it is possible, do it
    if(flag){
        for(unsigned i=0; i<4; i++){
            if(i!=index){
                int x = m_pos[i].first - m_pos[index].first;
                int y = m_pos[i].second - m_pos[index].second;
                if( (x<0 && y<0) || (x>0 && y>0) ){
                    m_pos[i].first = m_pos[index].first - x;
                }
                else if( (x>0 && y<0) || (x<0 && y>0) ){
                    m_pos[i].second = m_pos[index].second - y;
                
                }
                else if( y==0 ){
                    m_pos[i].first = m_pos[index].first;
                    m_pos[i].second = m_pos[index].second + x;

                }
                else if( x==0 ){
                    m_pos[i].first = m_pos[index].first - y;
                    m_pos[i].second = m_pos[index].second;
                }
                for(int k=0; k<2; k++){
                    if( m_pos[0].first > 9 || m_pos[1].first > 9 || m_pos[2].first > 9 || m_pos[3].first > 9 )
                        left();
                    else if( m_pos[0].first < 0 || m_pos[1].first < 0 || m_pos[2].first < 0 || m_pos[3].first < 0 )
                        right();
                    else if( m_pos[0].second > 19 || m_pos[1].second > 19 || m_pos[2].second > 19 || m_pos[3].second > 19 )
                        up();
                }
            }
        }
    }

}

