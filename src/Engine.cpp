#include "Engine.h"
#include <iostream>     // cout for debug only
#include <fstream>      // for read file ifstream
#include <cstring>

using namespace std;

Engine::Engine(int nx, int ny ) {
    this->nx = nx;
    this->ny = ny;

    //init tabs
    this->init();

    //example data
    this->t[5][4] = 1;
    this->t[5][5] = 1;
    this->t[5][6] = 1;

}

Engine::Engine(char file_name[]) {
    try{
        ifstream file;
        //char file_name[]="file.txt";
        file.open( file_name );
        if (file.is_open()) {
            //init from file
            int x, y = 0;
            string line;

            while(getline(file,line) ) {
                cout << "odczyt: "<< line << endl;
                if (y==0) {
                    //string wyjatek = "SSSS";
                    //throw  wyjatek;
                    this->ny =1;
                    this->nx =5;
                    if (this->ny<=0 || this->nx <= 0)
                    {
                        char message[] = "The size of the board must be greater than 0";
                        throw  message;
                    }
                }
                y++;
            }
            file.close();

            this->init();
        }
    }
    catch (char w[]) {
        this->error_message(w);
    }
    catch (...){
        this->error_message("There was an error");
    }
}

Engine::~Engine() {
    delete [] this->t;
    delete [] this->tmp;
}

void Engine::init() {
    this->t = new bool * [this->nx];
    this->tmp = new bool * [this->nx];

    for (int i=0;i<this->nx; i++){
        this->t[i] = new bool [this->ny];
        this->tmp[i] = new bool [this->ny];

        for (int y=0;y<this->ny; y++) {
            this->t[i][y] = 0;
            this->tmp[i][y] = 0;
        }
    }
}

/**
 * Analyze all elements of the array
 */
void Engine::analisys() {
    //warimlo zucoa
    //2 lub 3 zyzwe = bez zmian
    // 3 zywe => rodzi sie nowy
    // else obumiera
    for (int i=0;i<this->ny;i++) { // kolumny
        for (int j=0;j<this->nx;j++) { //wiersze
            //compare near items
            this->tmp[i][j] = this->compare(i,j);
        }
    }
}

/**
 * Compare nearby items
 */
int Engine::compare(int y, int x) {
    int alive = 0;
    //okreslenie maksymalnych wspolrzednych dla danego X oraz Y
    int min_x, max_x, min_y, max_y = 0;

    if (x-1>=0 && x+1<=this->nx-1) { // wiersze
        min_x = x-1;
        max_x = x+1;
    } else if (x-1>0) {
        min_x = x-1;
        max_x = x;
    } else if (x+1<=this->nx-1) {
        min_x = x;
        max_x = x+1;
    }

    if (y-1>=0 && y+1<=this->ny-1) { // kolumny
        min_y = y-1;
        max_y = y+1;
    } else if (y-1>0) {
        min_y = y-1;
        max_y = y;
    } else if (y+1<=this->ny-1) {
        min_y = y;
        max_y = y+1;
    }

    for (int i=min_y;i<=max_y;i++) {
        for (int j=min_x;j<=max_x;j++) {
            //wykluczenie punktu, ktory analizujemy ??
            if (i!=y || j!=x) {
                if (this->t[i][j]) {
                    alive++;
                }
            }
        }
    }
    cout << "FOR t[" << y << "][" << x << "]: " << alive << endl;

    //for debug use only
    if (this->is_debug()) {
        cout << "FOR t[" << y << "][" << x << "]:";
        cout << alive << endl;
        cout << "min_x: " << min_x << ", max_x: " << max_x << endl;
        cout << "min_y: " << min_y << ", max_y: " << max_y << endl;
        cout << endl;
    }

    //coditions
    if (alive > 1 && alive < 4 ) { // for 2 or 3
        return 1;//New born
    } else if (alive==1) { // for 1
        return this->t[y][x]; // no change
    } else {
        return 0; //Dies
    }
}

/**
 * Copy all items from this->tmp array to this->t.
 * Docelowo przeci¹¿enie operatora przypisywania lub kopiowania
 */
void Engine::copy(){
    for (int i=0;i<this->ny;i++) {
        for (int j=0;j<this->nx;j++) {
            this->t[i][j] = this->tmp[i][j];
            this->tmp[i][j] = 0; //reset temp array
        }
    }
}

void Engine::set_debug(bool status) {
    this->debug = status;
}

bool Engine::is_debug() {
    return this->debug;
}

void Engine::error_message(char message[]) {
    this->error = true;
    /*
    char * new_array = new char[std::strlen(*this->errors)+std::strlen(message)+1];
    strcpy(new_array, *this->errors);
    strcat(new_array, message);
    */
    *this->errors = message;
   // *this->errors = new_array;
}

bool Engine::is_errors() {
    return this->error;
}

