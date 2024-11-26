#include <iostream>
#include <string>
using namespace std;

class Piece
{
private:
    int x, y;
    int team_num;
    int life = 1;
    string name;
    int modify_num=1;

public:
    int chess_num;
    int GetX();
    int GetY();
    int GetTeamNum();
    int GetLife();
    string GetName();
    void SetX(int x);
    void SetY(int y);
    void SetLife(int life);
    void SetTeamNum(int life);
    void SetName(string name);
    void PrintName();
    int GetModify();
    void SetModify(int modify_num);
};