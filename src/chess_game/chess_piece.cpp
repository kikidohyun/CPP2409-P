#include "chess_piece.h"

int Piece::get_x(){
    return x;
}
int Piece::get_y(){
    return y;
}
int Piece::get_team_num(){
    return team_num;
}
int Piece::get_life(){
    return life;
}
string Piece::get_name(){
    return name;
}
void Piece::set_x(int x){
    this->x=x;
}
void Piece::set_y(int y){
    this->y=y;
}
void Piece::set_life(int life){
    this->life=life;
}
void Piece::set_team_num(int team_num){
    this->team_num=team_num;
}
void Piece::set_name(string name){
        this->name=name;
    }
void Piece::print_name(){
        cout<<name;
    }