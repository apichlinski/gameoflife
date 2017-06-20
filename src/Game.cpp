#include "Game.h"
/*
Game::Game(int nx, int ny ):Engine(nx, ny )    // Call the superclass constructor in the subclass' initialization list.
{
    // do something with bar
}
*/
void  Game::view() {

}

void  Game::view_temp() {

}
void  Game::display_error() {

}
void Game::start(int end) {
    if (!this->error) {
        //this->view();
        for (int i=0;i<end; i++) {
            this->analisys();
            this->copy();
            this->view();
        }
    } else {
        this->display_error();
    }
}
