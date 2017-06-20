#ifndef GAMEAPI_H
#define GAMEAPI_H
#include <windows.h>
#include "Game.h"

class GameAPI: public Game
{
    public:
        GameAPI(int nx, int ny ) : Game(nx, ny ) {}
        GameAPI(char file_name[] ) : Game(file_name ) {}
        void init_api(HWND hwnd);
        virtual void view();
        virtual void view_temp();
        virtual void display_error();
    protected:


    private:
        HWND _hwnd; // uchwyt okna
        HDC _hdc; // uchwyt pola roboczego
        HBRUSH _bgb, _fgb; //background brush, front brush
};

#endif // GAMEAPI_H
