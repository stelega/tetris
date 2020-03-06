#include "Game.h"


Game::Game(){
    window = new sf::RenderWindow(sf::VideoMode(800, 1000), "Tetris");
    run();
}


Game::~Game(){
    clear_board();
    delete window;
}


void Game::clear_board(){
    for( int i=0; i<13; i++ )
        delete[] arr[i];
    delete[] arr;
}


void Game::draw_background(){
    // displays number of points
    sf::Font font;
    if (!font.loadFromFile("../OpenSans-Italic.ttf"));    
    sf::Text text;
    text.setFont(font);
    text.setString("Points: " + std::to_string(points));
    text.setFillColor(sf::Color::Green);
    window->draw(text);

    // displays bounderies
    sf::RectangleShape rectangle1(sf::Vector2f( 491, 40 ));
    rectangle1.setPosition( 40, 40 );
    rectangle1.setFillColor(sf::Color(255,255,255,128));
    window->draw(rectangle1);

    sf::RectangleShape rectangle2(sf::Vector2f( 491, 40 ));
    rectangle2.setPosition( 40, 900 );
    rectangle2.setFillColor(sf::Color(255,255,255,128));
    window->draw(rectangle2);

    sf::RectangleShape rectangle3(sf::Vector2f( 40, 900 ));
    rectangle3.setPosition( 40, 40 );
    rectangle3.setFillColor(sf::Color(255,255,255,128));
    window->draw(rectangle3);

    sf::RectangleShape rectangle4(sf::Vector2f( 40, 900 ));
    rectangle4.setPosition( 491, 40 );
    rectangle4.setFillColor(sf::Color(255,255,255,128));
    window->draw(rectangle4);

    // displays vertical lines between fields
    sf::RectangleShape rectangles_vertical[11];
    for( int i=0; i<11; i++ ){
        rectangles_vertical[i] = sf::RectangleShape(sf::Vector2f(2, 820));
        rectangles_vertical[i].setPosition( 80 + i*40 + i, 80 );
        rectangles_vertical[i].setFillColor(sf::Color::White);
        window->draw(rectangles_vertical[i]);
    }

    // displays vertical lines between fields
    sf::RectangleShape rectangles_horizontal[21];
    for( int i=0; i<21; i++ ){
        rectangles_horizontal[i] = sf::RectangleShape(sf::Vector2f(412, 2));
        rectangles_horizontal[i].setPosition( 80, 80 + i*40 + i );
        rectangles_horizontal[i].setFillColor(sf::Color::White);
        window->draw(rectangles_horizontal[i]);
    }
}


void Game::draw_blocks(){
    for(int j=1; j<21; j++){
        for(int i=1; i<11; i++){
            if(arr[i][j] != sf::Color::Black){
                sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(40, 40));
                rectangle.setPosition( 41+i+40*i, 41+j+40*j );
                rectangle.setFillColor(arr[i][j]);
                window->draw(rectangle);
            }
        }
    }
}


void Game::draw_block( Block *block ){
    sf::Color color = block->get_color();
    sf::RectangleShape rectangle[4];
    for( unsigned i=0; i<4; i++){
        rectangle[i] = sf::RectangleShape(sf::Vector2f( 40, 40 ));
        rectangle[i].setPosition( 82 + 40*(*block)[i].first + (*block)[i].first, 82 + 40*(*block)[i].second + (*block)[i].second );
        rectangle[i].setFillColor(color);
        window->draw(rectangle[i]);
    }
}


Block* Game::rand_block( int num ){
    switch(num){
        case(0):
            return new Block0();
            break;
        case(1):
            return new Block1();
            break;
        case(2):
            return new Block2();
            break;
        case(3):
            return new Block3();
            break;
        case(4):
            return new Block4();
            break;
        case(5):
            return new Block5();
            break;
        default:
            return new Block6();
    }
}


void Game::run(){
    // allocating memory for array 'arr' and filling it with black color
    arr = new sf::Color*[13];
    for( int i=0; i<13; i++ ){
        arr[i] = new sf::Color[22];
        for(int j=0; j<22; j++){
            arr[i][j] = sf::Color::Black;
        }
    }
    // filling bounderies with grey color
    for(int i=0; i<13; i++){
        arr[i][0] = sf::Color(255,255,128);
        arr[i][21] = sf::Color(255,255,128);
    }
    for(int j=1; j<21; j++){
        arr[0][j] = sf::Color(255,255,128);
        arr[11][j] = sf::Color(255,255,128);
    }

    srand(time(NULL));
    Block* block = rand_block(rand()%7);

    while(window->isOpen()){

        sf::Event event;
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // clearing and displaying current board
        window->clear();
        draw_background();
        draw_blocks();
        draw_block(block);
        window->display();

        // checking if one of keys is pressed.
        // 'q' or 'escape' => quit a game
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
            break;
        // 'down' => move a current block down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(click_counter > 30){
                bool allowed = 1;
                for(int i=0; i<4; i++){
                    if( arr[(*block)[i].first+1][(*block)[i].second+2] != sf::Color::Black )
                        allowed = 0;
                }
                if( allowed ){
                    block->down();
                    click_counter = 0;
                }
            }
        }
        // 'up' => rotate current block
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(click_counter > 120){
                block->rotate(arr);
                click_counter = 0;
            }
        }
        // 'left' => move a current block left
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if(click_counter > 100){
                bool allowed = 1;
                for(int i=0; i<4; i++){
                    if( arr[(*block)[i].first][(*block)[i].second+1] != sf::Color::Black )
                        allowed = 0;
                }
                if( allowed ){
                    block->left();
                    click_counter = 0;
                }
            }
        }
        // 'right' => move a current block right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if(click_counter > 100 ){
                bool allowed = 1;
                for(int i=0; i<4; i++){
                    if( arr[(*block)[i].first+2][(*block)[i].second+1] != sf::Color::Black )
                        allowed = 0;
                }
                if( allowed ){
                    block->right();
                    click_counter = 0;
                }
            }
        }
        
        // checking if current block should move down
        if(time_counter > max_counter){
            bool allowed = 1;
            for(int i=0; i<4; i++){
                if( arr[(*block)[i].first+1][(*block)[i].second+2] != sf::Color::Black )
                    allowed = 0;
            }
            if( allowed ){
                block->down();
                time_counter = 0;
            }
            else{
                if(next_block){
                    for(int i=0; i<4; i++)
                        arr[(*block)[i].first+1][(*block)[i].second+1] = block->get_color();
                    
                    delete block;
                    block = rand_block(rand()%7);
                    for(int i=0; i<4; i++){
                        if(arr[(*block)[i].first+1][(*block)[i].second+1] != sf::Color::Black){
                            points = 0;
                            max_counter = 200;
                            clear_board();
                            run();
                        }
                    }
                    next_block = false;
                }
                else
                    next_block = true;
            }
        }

        // checking if theres a line where all fields are filled. If so, 
        // program clears that line and moves every block placed above down.
        for(int j=2; j<21; j++){
            bool b = true;
            for(int i=1; i<11; i++ ){
                if(arr[i][j] == sf::Color::Black ){
                    b = false;
                    break;
                }
            }
            if(b){
                points++;
                max_counter-=3;
                for( int k=j; k>=2; k-- ){
                    for( int i=1; i<11; i++ )
                        arr[i][k] = arr[i][k-1];
                }
                for( int i=1; i<11; i++)
                    arr[i][1] = sf::Color::Black;
            }
        }
        
        click_counter++;
        time_counter++;

    }

}
