#include "GameAPI.h"
#include <iostream>     // std::cout

using namespace std;

void GameAPI::view() {
    int fieldOffsetX = 0;
    int fieldOffsetY = 80;
    int fieldWidth = 20;
    int fieldHeight = 20;

    HBRUSH currentBrush;
    for (int y=0;y<this->ny;y++) {
        for (int i=0;i<this->nx;i++) {
            //cout << this->t[y][i];
            if (this->t[y][i]) {
                (HBRUSH)SelectObject(this->_hdc, this->_fgb);
            } else {
                (HBRUSH)SelectObject(this->_hdc, this->_bgb);
            }
            cout << (int)this->t[y][i];
            Rectangle( this->_hdc, fieldOffsetX+(i+1)*fieldWidth, fieldOffsetY+(y+1)*fieldHeight, fieldOffsetX+(i+2)*fieldWidth, fieldOffsetY+(y+2)*fieldHeight );
        }
        cout << endl;
    }

/*
    HBRUSH PedzelZiel, Pudelko;
    HPEN OlowekCzerw, Piornik;
    PedzelZiel = CreateSolidBrush( 0x00FF00 );
    OlowekCzerw = CreatePen( PS_DOT, 1, 0x0000FF );
    Pudelko =( HBRUSH ) SelectObject( this->_hdc, PedzelZiel );
    Piornik =( HPEN ) SelectObject( this->_hdc, OlowekCzerw );
    Rectangle( this->_hdc, 10, 10, 100, 100 );
    SelectObject( this->_hdc, Pudelko );
    SelectObject( this->_hdc, Piornik );
    DeleteObject( OlowekCzerw );
    DeleteObject( PedzelZiel );
*/
    ReleaseDC( this->_hwnd, this->_hdc );

    //MessageBox(this->_hwnd, "Aplikacja zakonczyla swój zywot!", "Status", MB_OK);
}

void  GameAPI::view_temp() {
    /*
    cout << endl << "TEMP: " <<endl;
    for (int y=0;y<this->ny;y++) {
        for (int i=0;i<this->nx;i++) {
            cout << this->tmp[y][i];
        }
        cout << endl;
    }
    cout << endl;
    */
}

void  GameAPI::display_error() {
    //cout << *this->errors << endl;
}

void GameAPI::init_api(HWND hwnd) {
    this->_hwnd = hwnd; //przekaz uchwyt okna
    this->_hdc = GetDC(hwnd); //pobierz HDC aktywnego okna
    this->_bgb = ::CreateSolidBrush(RGB(255,255,255));
    this->_fgb = ::CreateSolidBrush(RGB(0,0,0));
}
