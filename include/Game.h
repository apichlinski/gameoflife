#ifndef GAME_H
#define GAME_H

#include "Engine.h"

class Game : public Engine
{
    public:
        Game(int nx, int ny ) : Engine(nx, ny ) {}
        Game(char file_name[] ) : Engine(file_name ) {}
        void start(int end=1);
        virtual void view();
        virtual void view_temp();
        virtual void display_error();
    protected:

    private:

};

#endif // GAME_H
