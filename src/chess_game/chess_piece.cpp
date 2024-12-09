#include "chess_piece.h"

int Piece::GetX()
{
    return x;
}
int Piece::GetY()
{
    return y;
}
int Piece::GetTeamNum()
{
    return team_num;
}
int Piece::GetLife()
{
    return life;
}
string Piece::GetName()
{
    return name;
}
void Piece::SetX(int x)
{
    this->x = x;
}
void Piece::SetY(int y)
{
    this->y = y;
}
void Piece::SetLife(int life)
{
    this->life = life;
}
void Piece::SetTeamNum(int team_num)
{
    this->team_num = team_num;
}
void Piece::SetName(string name)
{
    this->name = name;
}
void Piece::PrintName()
{
    cout << name;
}