#ifndef ENGINE_H
#define ENGINE_H


class Engine
{
    private:

    public:
        Engine(int nx, int ny );
        Engine(char file_name[]);
        ~Engine();
        void init();
        void analisys();
        int compare(int x, int y);
        void copy();
        void set_debug(bool status);
        bool is_debug();
        void  error_message(char message[]);
        bool is_errors();

    protected:
        int nx, ny;
        bool ** t;
        bool ** tmp;
        bool debug=false;
        bool error=false;
        char * errors[];
};

#endif // ENGINE_H
