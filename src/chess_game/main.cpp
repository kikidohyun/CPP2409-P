#include <iostream>
#include <string>
using namespace std;
#include "chess_piece.h"
#include <cmath>

int board[8][8]={0};


void print_board(Piece chess_piece[2][16]);
void make_piece(Piece chess_piece[2][16]);
void board_copy(Piece chess_piece[2][16]);
void naming_piece(Piece chess_piece[2][16]);
void kill(Piece chess_piece[2][16],Piece &piece,int team_num);
bool board_check(Piece chess_piece[2][16],Piece &piece,int plus_x,int plus_y);
bool chess_rule(Piece &piece, int plus_x, int plus_y);



int main(){
    
    int k=1;
    int white_life;
    int black_life;

    Piece chess_piece[2][16];
    
    int choice;
    cout<<"1.체스 게임\n2.체스 퀴즈 제작\n 입력하시오"<<endl;
    cin>>choice;
    
    if(choice==1){
    make_piece(chess_piece);
    naming_piece(chess_piece);
    board_copy(chess_piece);
    while(1){
        int turn;
        int x,y;
        int moving_x,moving_y;
        white_life=0;
        black_life=0;
        
        print_board(chess_piece);
        if((k%2)==1){
            cout<<"1번째 플레이어의 차례입니다.\n";
            turn=0;
        }
        else{
            cout<<"2번째 플레이어의 차례입니다\n";
            turn=1;
        }
        cout<<"옮기고 싶은 기물의 x,y좌표를 입력하시오 (x좌표 0부터 시작, y좌표 0부터 시작)";
        cin>>x>>y;
        while(board[y][x]==0||(x<0||x>7||y<0||y>7)){
            cout<<"빈칸입니다 다시입력하시오"<<endl;
            cin>>x>>y;
        }
        
        

        for(int i=0;i<2;i++){
            for(int j=0;j<16;j++){
                if(x==chess_piece[i][j].get_x()&&y==chess_piece[i][j].get_y()){
                    if(turn==0){
                        if(turn!=chess_piece[i][j].get_team_num()){
                            cout<<"상대의 기물입니다. 다시 입력하십시오\n";
                            k++;
                            }
                        else{   
                                cout<<chess_piece[i][j].get_name()<<"입니다\n 원하는 x좌표 증가량과 y좌표 증가량을 입력하시오(x축은 오른쪽이 +, y축은 아래쪽이 +, 음수를 입력할 때는 x와y띄어쓰기 하지 말것)"<<endl;
                                cin>>moving_x>>moving_y;
                                while(!chess_rule(chess_piece[i][j],moving_x,moving_y)){
                                    cout<<"다시 입력하세요";
                                    cin>>moving_x>>moving_y;
                                    continue;
                                }
                                while(!board_check(chess_piece,chess_piece[i][j],moving_x,moving_y)){
                                    cout<<"다시 입력하세요";
                                    cin>>moving_x>>moving_y;
                                    continue;
                                }
                            
                                board_copy(chess_piece);
                        
                                
                       }
                    }
                    else{
                            if(turn!=chess_piece[i][j].get_team_num()){
                            cout<<"상대의 기물입니다. 다시 입력하십시오\n";
                            k++;
                            }
                        else{
                                cout<<chess_piece[i][j].get_name()<<"입니다\n 원하는 x좌표 증가량과 y좌표 증가량을 입력하시오(x축은 오른쪽이 +, y축은 아래쪽이 +)"<<endl;
                                cin>>moving_x>>moving_y;
                                while(!chess_rule(chess_piece[i][j],moving_x,moving_y)){
                                    cout<<"다시 입력하세요";
                                    cin>>moving_x>>moving_y;
                                    continue;
                                }
                                while(!board_check(chess_piece,chess_piece[i][j],moving_x,moving_y)){
                                    cout<<"다시 입력하세요";
                                    cin>>moving_x>>moving_y;
                                    continue;
                                }
                                board_copy(chess_piece);
                                
                            
                                
                        }

                    }

                }
             }
       
        }

        
            if(chess_piece[0][11].get_life()==1){
                white_life=1;
            }
        
            if(chess_piece[1][11].get_life()==1){
                black_life=1;
            }
        
        if(white_life==0){
            cout<<"2째 플레이어가 승리하셨습니다.";
            break;
        }
        else if(black_life==0){
            cout<<"1번째 플레이어가 승리하셨습니다";
            break;
        }
        k++; 
    }
    
    
    }
    return 0;
}

void print_board(Piece chess_piece[2][16]) {
    int x, y;
    for (int i = 0; i < 8; i++) {
        cout << "|------|------|------|------|------|------|------|------|" << endl;
        for (int j = 0; j < 8; j++) {
            cout << "|";
            bool found = false;
            for (int q = 0; q < 2; q++) {
                for (int w = 0; w < 16; w++) {
                    x = chess_piece[q][w].get_x();
                    y = chess_piece[q][w].get_y();
                    if (x == j && y == i) {
                        chess_piece[q][w].print_name();
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (!found) cout << "      ";
        }
        cout << "|" << endl;
    }
    cout << "|------|------|------|------|------|------|------|------|" << endl;
}


void make_piece(Piece chess_piece[2][16]){
    for(int i=0;i<2;i++){
        for(int j=0;j<16;j++){
            if(i==0){
                chess_piece[i][j].set_team_num(0);
            }
            else{
                chess_piece[i][j].set_team_num(1);
            }
            if(chess_piece[i][j].get_team_num()==0){
                if(j<8){
                    chess_piece[i][j].set_x(j);
                    chess_piece[i][j].set_y(1);
                }
                else{
                    chess_piece[i][j].set_x(j-8);
                    chess_piece[i][j].set_y(0);
                }
            }

            if(chess_piece[i][j].get_team_num()==1){
                if(j<8){
                    chess_piece[i][j].set_x(j);
                    chess_piece[i][j].set_y(6);
                }
                else{
                    chess_piece[i][j].set_x(j-8);
                    chess_piece[i][j].set_y(7);
                }
            }
        }
    }

}


void board_copy(Piece chess_piece[2][16]){
     int x,y;
     for(int i=0;i<2;i++){
         for(int j=0;j<16;j++){
            x=chess_piece[i][j].get_y();
            y=chess_piece[i][j].get_x();
            if(chess_piece[i][j].get_team_num()==0){
                board[x][y]=1;}
            else{
                board[x][y]=2;
            }
         }
    }
}

void naming_piece(Piece chess_piece[2][16]){
    for(int i=0;i<2;i++){
        for(int j=0;j<16;j++){
            if(i==0){
                if(chess_piece[i][j].get_y()==1){
                    chess_piece[i][j].set_name("폰   1");
                }
                else if(chess_piece[i][j].get_x()==0||chess_piece[i][j].get_x()==7){
                    chess_piece[i][j].set_name("룩   1");
                }
                else if(chess_piece[i][j].get_x()==1||chess_piece[i][j].get_x()==6){
                    chess_piece[i][j].set_name("낫트 1");
                }
                else if(chess_piece[i][j].get_x()==2||chess_piece[i][j].get_x()==5){
                    chess_piece[i][j].set_name("비숍 1");
                }
                else if(chess_piece[i][j].get_x()==3){
                    chess_piece[i][j].set_name("킹   1");
                }
                else{
                    chess_piece[i][j].set_name("퀸   1");
                }

            }
            else{
                 if(chess_piece[i][j].get_y()==6){
                    chess_piece[i][j].set_name("폰   2");
                }
                else if(chess_piece[i][j].get_x()==0||chess_piece[i][j].get_x()==7){
                    chess_piece[i][j].set_name("룩   2");
                }
                else if(chess_piece[i][j].get_x()==1||chess_piece[i][j].get_x()==6){
                    chess_piece[i][j].set_name("낫트 2");
                }
                else if(chess_piece[i][j].get_x()==2||chess_piece[i][j].get_x()==5){
                    chess_piece[i][j].set_name("비숍 2");
                }
                else if(chess_piece[i][j].get_x()==3){
                    chess_piece[i][j].set_name("킹   2");
                }
                else{
                    chess_piece[i][j].set_name("퀸   2");
                }

            }
        }
    } 

}


void kill(Piece chess_piece[2][16],Piece &piece,int team_num){
    int x=piece.get_x();
    int y=piece.get_y();
    for(int i=0;i<16;i++){
        if(team_num==0){
            if(chess_piece[1][i].get_x()==x&&chess_piece[1][i].get_y()==y){
                chess_piece[1][i].set_life(0);
                chess_piece[1][i].set_x(-1);
                chess_piece[1][i].set_y(-1);
                board[y][x]=1;
            }
        }
        else{
            if(chess_piece[0][i].get_x()==x&&chess_piece[0][i].get_y()==y){
                chess_piece[0][i].set_life(0);
                chess_piece[0][i].set_x(-1);
                chess_piece[0][i].set_y(-1);
                board[y][x]=2;
            }
        }
    }
}


bool board_check(Piece chess_piece[2][16],Piece &piece,int plus_x,int plus_y){
    int original_x = piece.get_x();
    int original_y = piece.get_y();
    int new_x = original_x + plus_x;
    int new_y = original_y + plus_y;
    piece.set_x(new_x);
    piece.set_y(new_y);
   int x=new_x;
   int y=new_y; 
        if(piece.get_team_num()==0){
            if(board[y][x]==1){
                cout<<"해당 위치에 같은 팀 기물이 있습니다.\n";
                piece.set_x(original_x);
                piece.set_y(original_y);
                return false;
            }
            else if(board[y][x]==2){
                cout<<"상대팀 기물을 잡았습니다.\n"; 
                kill(chess_piece,piece,0);
                board[original_y][original_x]=0;
                return true;
            }
            else{
                cout<<"해당 위치로 이동합니다.\n";
                board[original_y][original_x]=0;
                return true;           //빈칸일 때
            }
        }
        else{
            if(board[y][x]==2){
                cout<<"해당 위치에 같은 팀 기물이 있습니다.\n";
                cout<<x<<" "<<y<<endl;
                piece.set_x(original_x);
                piece.set_y(original_y);
                return false;
            }
            else if(board[y][x]==1){
                cout<<"상대팀 기물을 잡았습니다.\n"; 
                kill(chess_piece,piece,1);
                board[original_y][original_x]=0;
                return true;
            }
            else{
                cout<<"해당 위치로 이동합니다.\n";
                board[original_y][original_x]=0;
                return true;           //빈칸일 때
            }

        }

}


bool chess_rule(Piece &piece, int plus_x, int plus_y) {
    int original_x = piece.get_x();
    int original_y = piece.get_y();
    int new_x = original_x + plus_x;
    int new_y = original_y + plus_y;

    
    if (new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7) {
        cout << "기물의 움직임이 체스판 범위를 벗어났습니다.\n";
        return false;
    }

   
    string name = piece.get_name();
    if (name.find("폰") != string::npos) { 
        if (piece.get_team_num() == 0) { 
            if (!(plus_x == 0 && (plus_y == 1 || (original_y == 1 && plus_y == 2)))) {
                cout << "폰의 움직임이 바르지 않습니다.\n";
                return false;
            }
        } else { 
            if (!(plus_x == 0 && (plus_y == -1 || (original_y == 6 && plus_y == -2)))) {
                cout << "폰의 움직임이 바르지 않습니다.\n";
                return false;
            }
        }
    } else if (name.find("룩") != string::npos) { 
        if (!(plus_x == 0 || plus_y == 0)) {
            cout << "룩의 움직임이 바르지 않습니다.\n";
            return false;
        }
    } else if (name.find("낫트") != string::npos) { 
        if (!((abs(plus_x) == 2 && abs(plus_y) == 1) || (abs(plus_x) == 1 && abs(plus_y) == 2))) {
            cout << "낫트의 움직임이 바르지 않습니다.\n";
            return false;
        }
    } else if (name.find("비숍") != string::npos) { 
        if (abs(plus_x) != abs(plus_y)) {
            cout << "비숍의 움직임이 바르지 않습니다.\n";
            return false;
        }
    } else if (name.find("킹") != string::npos) { 
        if (abs(plus_x) > 1 || abs(plus_y) > 1) {
            cout << "킹의 움직임이 바르지 않습니다.\n";
            return false;
        }
    } else if (name.find("퀸") != string::npos) { 
        if (!(abs(plus_x) == abs(plus_y) || plus_x == 0 || plus_y == 0)) {
            cout << "퀸의 움직임이 바르지 않습니다.\n";
            return false;
        }
    }

    return true;
}
