#include <iostream>
#include <string>
using namespace std;

class Piece{
private:
    int x,y;
    int team_num;
    int life=1;
    string name;
    
public:
    int chess_num;
    int get_x();
    int get_y();
    int get_team_num();
    int get_life();
    string get_name();
    void set_x(int x);
    void set_y(int y);
    void set_life(int life);
    void set_team_num(int life);
    void set_name(string name);
    void print_name();
};