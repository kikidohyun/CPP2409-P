#include <iostream>
#include <string>
using namespace std;
#include "chess_piece.h"
#include <cmath>

int board[8][8] = {0};

void PrintBoard(Piece chess_piece[2][16]);
void MakePiece(Piece chess_piece[2][16]);
void BoardCopy(Piece chess_piece[2][16]);
void NamingPiece(Piece chess_piece[2][16]);
void Kill(Piece chess_piece[2][16], Piece &piece, int team_num);
bool BoardCheck(Piece chess_piece[2][16], Piece &piece, int plus_x, int plus_y);
bool ChessRule(Piece &piece, int plus_x, int plus_y);

int main()
{

    int k = 1;
    int white_life;
    int black_life;
    int choice;

    Piece chess_piece[2][16];
    MakePiece(chess_piece);
    NamingPiece(chess_piece);
    BoardCopy(chess_piece);

    do
    {
        cout << "1.체스 게임\n2.체스 퀴즈 제작\n 입력하시오" << endl;
        cin >> choice;
        if (choice != 1 && choice != 2)
        {
            cout << "잘못된 입력값입니다." << endl;
            continue;
        }
        break;
    } while (1);

    if (choice == 2)
    {

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                chess_piece[i][j].SetModify(0);
                chess_piece[i][j].SetX(-1);
                chess_piece[i][j].SetY(-1);
                chess_piece[i][j].SetLife(0);
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = 0;
            }
        }

        PrintBoard(chess_piece);
        cout << "체스 퀴즈 제작을 시작합니다." << endl;

        while (1)
        {
            int num;
            int x_dot, y_dot;
            int play_game = 0;
            int delete_num;
            Piece *choice_piece;
            cout << "1. 기물 추가 or 게임 실행\n2. 기물 삭제\n";
            cin >> delete_num;
            if (delete_num == 1)
            {
                cout << "놓고싶은 기물과 팀에 해당하는 번호를 입력하시오 (만들어진 체스판에서 체스를 실행하고 싶다면 0을 입력하시오)" << endl;
                cout << "1.폰 1\n2.룩 1\n3.낫트 1\n4.비숍 1\n5.퀸 1\n6.킹 1\n7.폰 2\n8.룩 2\n9.나이트 2\n10.비숍 2\n11.퀸 2\n12.킹 2\n";
                cin >> num;

                while (1)
                {
                    if (num == 1)
                    {
                        for (int i = 0; i < 7; i++)
                        {
                            if (chess_piece[0][i].GetLife() == 0)
                            {
                                choice_piece = &chess_piece[0][i];
                                break;
                            }
                        }
                        break;
                    }
                    else if (num == 2)
                    {
                        if (chess_piece[0][8].GetLife() == 1)
                        {
                            choice_piece = &chess_piece[0][15];
                        }
                        else
                        {
                            choice_piece = &chess_piece[0][8];
                        }

                        break;
                    }
                    else if (num == 3)
                    {
                        if (chess_piece[0][9].GetLife() == 1)
                        {
                            choice_piece = &chess_piece[0][14];
                        }
                        else
                        {
                            choice_piece = &chess_piece[0][9];
                        }

                        break;
                    }
                    else if (num == 4)
                    {
                        if (chess_piece[0][10].GetLife() == 1)
                        {
                            choice_piece = &chess_piece[0][13];
                        }
                        else
                        {
                            choice_piece = &chess_piece[0][10];
                        }

                        break;
                    }
                    else if (num == 5)
                    {
                        choice_piece = &chess_piece[0][11];
                        break;
                    }
                    else if (num == 6)
                    {
                        choice_piece = &chess_piece[0][12];
                        break;
                    }
                    else if (num == 7)
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            if (chess_piece[1][i].GetLife() == 0)
                            {
                                choice_piece = &chess_piece[1][i];
                                break;
                            }
                        }
                        break;
                    }
                    else if (num == 8)
                    {
                        if (chess_piece[1][8].GetLife() == 1)
                        {
                            choice_piece = &chess_piece[1][15];
                        }
                        else
                        {
                            choice_piece = &chess_piece[1][8];
                        }

                        break;
                    }
                    else if (num == 9)
                    {
                        if (chess_piece[1][9].GetLife() == 1)
                        {
                            choice_piece = &chess_piece[1][14];
                        }
                        else
                        {
                            choice_piece = &chess_piece[1][9];
                        }

                        break;
                    }
                    else if (num == 10)
                    {
                        if (chess_piece[1][10].GetLife() == 1)
                        {
                            choice_piece = &chess_piece[1][13];
                        }
                        else
                        {
                            choice_piece = &chess_piece[1][10];
                        }

                        break;
                    }
                    else if (num == 11)
                    {
                        choice_piece = &chess_piece[1][11];
                        break;
                    }
                    else if (num == 12)
                    {
                        choice_piece = &chess_piece[1][12];
                        break;
                    }
                    else if (num == 0)
                    {
                        play_game = 1;
                        break;
                    }
                    else
                    {
                        cout << "잘못 입력하셨습니다.";
                    }
                }
                if (play_game == 1)
                {
                    if (chess_piece[0][12].GetLife() == 0 || chess_piece[1][12].GetLife() == 0)
                    {
                        cout << "king 기물이 없기에 게임을 진행할 수 없습니다." << endl;
                        continue;
                    }
                    BoardCopy(chess_piece);
                    break;
                }

                do
                {
                    cout << "기물을 놓고싶은 x좌표와 y좌표를 입력해 주세요(좌표는 0부터 시작합니다),(말을 잘못 고르셨다면 x,y값에 -1을 넣으세요)" << endl;
                    cin >> x_dot >> y_dot;
                    if (x_dot < 0 || x_dot > 8 || y_dot < 0 || y_dot > 8 || (board[y_dot][x_dot] != 0))
                    {
                        cout << "잘못된 좌표값입니다." << endl;
                        continue;
                    }
                    break;
                } while (1);

                if (x_dot == -1 && y_dot == -1)
                {
                    continue;
                }
                choice_piece->SetX(x_dot);
                choice_piece->SetY(y_dot);
                choice_piece->SetModify(1);
                choice_piece->SetLife(1);
                BoardCopy(chess_piece);
                PrintBoard(chess_piece);
            }
            else
            {
                int delete_x, delete_y;
                do
                {
                    cout << "삭제하고 싶은 기물의 좌표를 입력하시오(x축은 오른쪽이 +, y축은 아래쪽이 +,좌표는 0부터 시작합니다)" << endl;
                    cin >> delete_x >> delete_y;
                    if (delete_x < 0 || delete_x > 8 || delete_y < 0 || delete_y > 8)
                    {
                        cout << "잘못된 좌표값입니다." << endl;
                        continue;
                    }
                    break;
                } while (1);
                if (board[delete_y][delete_x] == 0)
                {
                    cout << "해당 위치에는 말이 없습니다." << endl;
                }
                else
                {
                    for (int i = 0; i < 2; i++)
                    {
                        for (int j = 0; j < 16; j++)
                        {
                            if (chess_piece[i][j].GetX() == delete_x && chess_piece[i][j].GetY() == delete_y)
                            {
                                chess_piece[i][j].SetX(-1);
                                chess_piece[i][j].SetY(-1);
                                chess_piece[i][j].SetModify(0);
                                chess_piece[i][j].SetLife(0);
                                BoardCopy(chess_piece);
                                PrintBoard(chess_piece);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    while (1)
    {
        int turn;
        int x, y;
        int moving_x, moving_y;
        white_life = 0;
        black_life = 0;

        PrintBoard(chess_piece);
        if ((k % 2) == 1)
        {
            cout << "1번째 플레이어의 차례입니다.\n";
            turn = 0;
        }
        else
        {
            cout << "2번째 플레이어의 차례입니다\n";
            turn = 1;
        }
        cout << "옮기고 싶은 기물의 x,y좌표를 입력하시오 (x축은 오른쪽이 +, y축은 아래쪽이 +,좌표는 0부터 시작합니다)";
        cin >> x >> y;
        while (board[y][x] == 0 || (x < 0 || x > 7 || y < 0 || y > 7))
        {
            cout << "빈칸입니다 다시입력하시오" << endl;
            cin >> x >> y;
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                if (x == chess_piece[i][j].GetX() && y == chess_piece[i][j].GetY())
                {
                    if (turn == 0)
                    {
                        if (turn != chess_piece[i][j].GetTeamNum())
                        {
                            cout << "상대의 기물입니다. 다시 입력하십시오\n";
                            k++;
                        }
                        else
                        {
                            cout << chess_piece[i][j].GetName() << "입니다\n원하는 x좌표 증가량과 y좌표 증가량을 입력하시오(x,y축은 0부터 시작합니다. x축은 오른쪽이 +, y축은 아래쪽이 + ,만약 다른 말을 입력하고 싶다면 x,y에 -1을 입력하세요)" << endl;
                            cin >> moving_x >> moving_y;

                            while (1)
                            {
                                if (moving_x == -1 && moving_y == -1)
                                {
                                    k++;
                                    break;
                                }
                                int check = 1;
                                if (ChessRule(chess_piece[i][j], moving_x, moving_y))
                                {
                                    while (!BoardCheck(chess_piece, chess_piece[i][j], moving_x, moving_y))
                                    {
                                        check = 0;
                                        cout << "다시 입력하세요 (만약 다른 말을 입력하고 싶다면 x,y에 -1을 입력하세요)";
                                        cin >> moving_x >> moving_y;
                                        break;
                                    }
                                    if (check == 1)
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    cout << "다시 입력하세요 (만약 다른 말을 입력하고 싶다면 x,y에 -1을 입력하세요)";
                                    cin >> moving_x >> moving_y;
                                }
                            }

                            BoardCopy(chess_piece);
                        }
                    }
                    else
                    {
                        if (turn != chess_piece[i][j].GetTeamNum())
                        {
                            cout << "상대의 기물입니다. 다시 입력하십시오\n";
                            k++;
                        }
                        else
                        {
                            cout << chess_piece[i][j].GetName() << "입니다\n원하는 x좌표 증가량과 y좌표 증가량을 입력하시오(x,y축은 0부터 시작합니다. x축은 오른쪽이 +, y축은 아래쪽이 + ,만약 다른 말을 입력하고 싶다면 x,y에 -1을 입력하세요)" << endl;
                            cin >> moving_x >> moving_y;

                            while (1)
                            {
                                if (moving_x == -1 && moving_y == -1)
                                {
                                    k++;
                                    break;
                                }
                                if (ChessRule(chess_piece[i][j], moving_x, moving_y))
                                {
                                    while (!BoardCheck(chess_piece, chess_piece[i][j], moving_x, moving_y))
                                    {
                                        cout << "다시 입력하세요 (만약 다른 말을 입력하고 싶다면 x,y에 -1을 입력하세요)";
                                        cin >> moving_x >> moving_y;
                                        break;
                                    }
                                    break;
                                }
                                else
                                {
                                    cout << "다시 입력하세요 (만약 다른 말을 입력하고 싶다면 x,y에 -1을 입력하세요)";
                                    cin >> moving_x >> moving_y;
                                }
                            }

                            BoardCopy(chess_piece);
                        }
                    }
                }
            }
        }

        if (chess_piece[0][12].GetLife() == 1)
        {
            white_life = 1;
        }

        if (chess_piece[1][12].GetLife() == 1)
        {
            black_life = 1;
        }

        if (white_life == 0)
        {
            cout << "2째 플레이어가 승리하셨습니다.";
            break;
        }
        else if (black_life == 0)
        {
            cout << "1번째 플레이어가 승리하셨습니다";
            break;
        }
        k++;
    }

    return 0;
}

void PrintBoard(Piece chess_piece[2][16])
{
    int x, y;
    for (int i = 0; i < 8; i++)
    {
        cout << "|------|------|------|------|------|------|------|------|" << endl;
        for (int j = 0; j < 8; j++)
        {
            cout << "|";
            bool found = false;
            for (int q = 0; q < 2; q++)
            {
                for (int w = 0; w < 16; w++)
                {
                    x = chess_piece[q][w].GetX();
                    y = chess_piece[q][w].GetY();
                    if (x == j && y == i && chess_piece[q][w].GetModify() == 1)
                    {
                        chess_piece[q][w].PrintName();
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (!found)
                cout << "      ";
        }
        cout << "|" << endl;
    }
    cout << "|------|------|------|------|------|------|------|------|" << endl;
}

void MakePiece(Piece chess_piece[2][16])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (i == 0)
            {
                chess_piece[i][j].SetTeamNum(0);
            }
            else
            {
                chess_piece[i][j].SetTeamNum(1);
            }
            if (chess_piece[i][j].GetTeamNum() == 0)
            {
                if (j < 8)
                {
                    chess_piece[i][j].SetX(j);
                    chess_piece[i][j].SetY(1);
                }
                else
                {
                    chess_piece[i][j].SetX(j - 8);
                    chess_piece[i][j].SetY(0);
                }
            }

            if (chess_piece[i][j].GetTeamNum() == 1)
            {
                if (j < 8)
                {
                    chess_piece[i][j].SetX(j);
                    chess_piece[i][j].SetY(6);
                }
                else
                {
                    chess_piece[i][j].SetX(j - 8);
                    chess_piece[i][j].SetY(7);
                }
            }
        }
    }
}

void BoardCopy(Piece chess_piece[2][16])
{
    int x, y;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            x = chess_piece[i][j].GetY();
            y = chess_piece[i][j].GetX();
            if (chess_piece[i][j].GetTeamNum() == 0)
            {
                board[x][y] = 1;
            }
            else
            {
                board[x][y] = 2;
            }
        }
    }
}

void NamingPiece(Piece chess_piece[2][16])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (i == 0)
            {
                if (chess_piece[i][j].GetY() == 1)
                {
                    chess_piece[i][j].SetName("폰   1");
                }
                else if (chess_piece[i][j].GetX() == 0 || chess_piece[i][j].GetX() == 7)
                {
                    chess_piece[i][j].SetName("룩   1");
                }
                else if (chess_piece[i][j].GetX() == 1 || chess_piece[i][j].GetX() == 6)
                {
                    chess_piece[i][j].SetName("낫트 1");
                }
                else if (chess_piece[i][j].GetX() == 2 || chess_piece[i][j].GetX() == 5)
                {
                    chess_piece[i][j].SetName("비숍 1");
                }
                else if (chess_piece[i][j].GetX() == 3)
                {
                    chess_piece[i][j].SetName("퀸   1");
                }
                else
                {
                    chess_piece[i][j].SetName("킹   1");
                }
            }
            else
            {
                if (chess_piece[i][j].GetY() == 6)
                {
                    chess_piece[i][j].SetName("폰   2");
                }
                else if (chess_piece[i][j].GetX() == 0 || chess_piece[i][j].GetX() == 7)
                {
                    chess_piece[i][j].SetName("룩   2");
                }
                else if (chess_piece[i][j].GetX() == 1 || chess_piece[i][j].GetX() == 6)
                {
                    chess_piece[i][j].SetName("낫트 2");
                }
                else if (chess_piece[i][j].GetX() == 2 || chess_piece[i][j].GetX() == 5)
                {
                    chess_piece[i][j].SetName("비숍 2");
                }
                else if (chess_piece[i][j].GetX() == 3)
                {
                    chess_piece[i][j].SetName("퀸   2");
                }
                else
                {
                    chess_piece[i][j].SetName("킹   2");
                }
            }
        }
    }
}

void Kill(Piece chess_piece[2][16], Piece &piece, int team_num)
{
    int x = piece.GetX();
    int y = piece.GetY();
    for (int i = 0; i < 16; i++)
    {
        if (team_num == 0)
        {
            if (chess_piece[1][i].GetX() == x && chess_piece[1][i].GetY() == y)
            {
                chess_piece[1][i].SetLife(0);
                chess_piece[1][i].SetX(-1);
                chess_piece[1][i].SetY(-1);
                board[y][x] = 1;
            }
        }
        else
        {
            if (chess_piece[0][i].GetX() == x && chess_piece[0][i].GetY() == y)
            {
                chess_piece[0][i].SetLife(0);
                chess_piece[0][i].SetX(-1);
                chess_piece[0][i].SetY(-1);
                board[y][x] = 2;
            }
        }
    }
}

bool BoardCheck(Piece chess_piece[2][16], Piece &piece, int plus_x, int plus_y)
{
    int original_x = piece.GetX();
    int original_y = piece.GetY();
    int new_x = original_x + plus_x;
    int new_y = original_y + plus_y;
    int x = new_x;
    int y = new_y;

    if (new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7)
    {
        cout << "기물의 움직임이 체스판 범위를 벗어났습니다.\n";
        return false;
    }

    piece.SetX(new_x);
    piece.SetY(new_y);

    if (piece.GetTeamNum() == 0)
    {
        if (board[y][x] == 1)
        {
            cout << "해당 위치에 같은 팀 기물이 있습니다.\n";
            piece.SetX(original_x);
            piece.SetY(original_y);
            return false;
        }
        else if (board[y][x] == 2)
        {
            cout << "상대팀 기물을 잡았습니다.\n";
            Kill(chess_piece, piece, 0);
            board[original_y][original_x] = 0;
            return true;
        }
        else
        {
            cout << "해당 위치로 이동합니다.\n";
            board[original_y][original_x] = 0;
            return true; // 빈칸일 때
        }
    }
    else
    {
        if (board[y][x] == 2)
        {
            cout << "해당 위치에 같은 팀 기물이 있습니다.\n";
            cout << x << " " << y << endl;
            piece.SetX(original_x);
            piece.SetY(original_y);
            return false;
        }
        else if (board[y][x] == 1)
        {
            cout << "상대팀 기물을 잡았습니다.\n";
            Kill(chess_piece, piece, 1);
            board[original_y][original_x] = 0;
            return true;
        }
        else
        {
            cout << "해당 위치로 이동합니다.\n";
            board[original_y][original_x] = 0;
            return true; // 빈칸일 때
        }
    }
}

bool ChessRule(Piece &piece, int plus_x, int plus_y)
{
    int original_x = piece.GetX();
    int original_y = piece.GetY();
    int new_x = original_x + plus_x;
    int new_y = original_y + plus_y;

    string name = piece.GetName();
    if (name.find("폰") != string::npos)
    {
        if (piece.GetTeamNum() == 0)
        {
            if (!(plus_x == 0 && (plus_y == 1 || (original_y == 1 && plus_y == 2))))
            {
                if (board[original_y + 1][original_x + 1] == 2 || board[original_y + 1][original_x - 1] == 2)
                {
                    if (plus_y == 1 && (plus_x == 1 || plus_x == -1))
                    {
                        return true;
                    }
                }
                else
                {
                    cout << "폰의 움직임이 바르지 않습니다.\n";
                    return false;
                }
            }
            else
            {
                for (int i = 1; i < plus_y; i++)
                {
                    if (board[original_y + i][original_x] != 0)
                    {
                        cout << "해당 경로가 막혀있습니다\n";
                        return false;
                    }
                }
                if ((plus_y == 1 && board[original_y + 1][original_x] == 2) || (plus_y == 2 && board[original_y + 2][original_x] == 2))
                {
                    cout << "폰은 직선으로 상대 기물을 잡을 수 없습니다.\n";
                    return false;
                }
            }
        }
        else
        {
            if (!(plus_x == 0 && (plus_y == -1 || (original_y == 6 && plus_y == -2))))
            {
                if (board[original_y - 1][original_x + 1] == 1 || board[original_y - 1][original_x - 1] == 1)
                {
                    if (plus_y == -1 && (plus_x == 1 || plus_x == -1))
                    {
                        return true;
                    }
                }
                else
                {
                    cout << "폰의 움직임이 바르지 않습니다.\n";
                    return false;
                }
            }
            else
            {
                for (int i = -1; i > plus_y; i--)
                {
                    if (board[original_y + i][original_x] != 0)
                    {
                        cout << "해당 경로가 막혀있습니다\n";
                        return false;
                    }
                }

                if ((plus_y == -1 && board[original_y - 1][original_x] == 1) || (plus_y == -2 && board[original_y - 2][original_x] == 1))
                {
                    cout << "폰은 직선으로 상대 기물을 잡을 수 없습니다.\n";
                    return false;
                }
            }
        }
    }
    else if (name.find("룩") != string::npos)
    {
        if (!(plus_x == 0 || plus_y == 0))
        {
            cout << "룩의 움직임이 바르지 않습니다.\n";
            return false;
        }
        else
        {
            if (plus_x == 0)
            {
                if (plus_y > 0)
                {
                    for (int i = 1; i < plus_y; i++)
                    {
                        if (board[original_y + i][original_x] != 0)
                        {
                            cout << "해당 경로가 막혀있습니다.\n";
                            return false;
                        }
                    }
                }
                else
                {
                    for (int i = -1; i > plus_y; i--)
                    {
                        if (board[original_y + i][original_x] != 0)
                        {
                            cout << "해당 경로가 막혀있습니다.\n";
                            return false;
                        }
                    }
                }
            }
            else
            {
                if (plus_x > 0)
                {
                    for (int i = 1; i < plus_x; i++)
                    {
                        if (board[original_y][original_x + i] != 0)
                        {
                            cout << "해당 경로가 막혀있습니다.\n";
                            return false;
                        }
                    }
                }
                else
                {
                    for (int i = -1; i > plus_x; i--)
                    {
                        if (board[original_y][original_x + i] != 0)
                        {
                            cout << "해당 경로가 막혀있습니다.\n";
                            return false;
                        }
                    }
                }
            }
        }
    }
    else if (name.find("낫트") != string::npos)
    {
        if (!((abs(plus_x) == 2 && abs(plus_y) == 1) || (abs(plus_x) == 1 && abs(plus_y) == 2)))
        {
            cout << "낫트의 움직임이 바르지 않습니다.\n";
            return false;
        }
    }
    else if (name.find("비숍") != string::npos)
    {
        if (abs(plus_x) != abs(plus_y))
        {
            cout << "비숍의 움직임이 바르지 않습니다.\n";
            return false;
        }
        else
        {
            if (plus_x > 0)
            {
                if (plus_y > 0)
                {
                    for (int i = 1; i < plus_y; i++)
                    {
                        for (int j = 1; j < plus_x; j++)
                        {

                            if (board[original_y + i][original_x + j] != 0)
                            {
                                cout << "해당 경로가 막혀있습니다.\n";
                                return false;
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i > plus_y; i--)
                    {
                        for (int j = 0; j < plus_x; j++)
                        {

                            if (board[original_y + i][original_x + j] != 0)
                            {
                                cout << "해당 경로가 막혀있습니다.\n";
                                return false;
                            }
                        }
                    }
                }
            }
            else
            {
                if (plus_y > 0)
                {
                    for (int i = 0; i < plus_y; i++)
                    {
                        for (int j = 0; j > plus_x; j--)
                        {

                            if (board[original_y + i][original_x + j] != 0)
                            {
                                cout << "해당 경로가 막혀있습니다.\n";
                                return false;
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i > plus_y; i--)
                    {
                        for (int j = 0; j > plus_x; j--)
                        {

                            if (board[original_y + i][original_x + j] != 0)
                            {
                                cout << "해당 경로가 막혀있습니다.\n";
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (name.find("킹") != string::npos)
    {
        if (abs(plus_x) > 1 || abs(plus_y) > 1)
        {
            cout << "킹의 움직임이 바르지 않습니다.\n";
            return false;
        }
    }
    else if (name.find("퀸") != string::npos)
    {
        if (!(abs(plus_x) == abs(plus_y) || plus_x == 0 || plus_y == 0))
        {
            cout << "퀸의 움직임이 바르지 않습니다.\n";
            return false;
        }
        else if (abs(plus_x) == abs(plus_y))
        {
            if (plus_x > 0)
            {
                if (plus_y > 0)
                {
                    for (int i = 0; i < plus_y; i++)
                    {
                        for (int j = 0; j < plus_x; j++)
                        {

                            if (board[original_y + i][original_x + j] != 0)
                            {
                                cout << "해당 경로가 막혀있습니다.\n";
                                return false;
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i > plus_y; i--)
                    {
                        for (int j = 0; j < plus_x; j++)
                        {

                            if (board[original_y + i][original_x + j] != 0)
                            {
                                cout << "해당 경로가 막혀있습니다.\n";
                                return false;
                            }
                        }
                    }
                }
            }
            else
            {
                if (plus_y > 0)
                {
                    for (int i = 0; i < plus_y; i++)
                    {
                        for (int j = 0; j > plus_x; j--)
                        {

                            if (board[original_y + i][original_x + j] != 0)
                            {
                                cout << "해당 경로가 막혀있습니다.\n";
                                return false;
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i > plus_y; i--)
                    {
                        for (int j = 0; j > plus_x; j--)
                        {

                            if (board[original_y + i][original_x + j] != 0)
                            {
                                cout << "해당 경로가 막혀있습니다.\n";
                                return false;
                            }
                        }
                    }
                }
            }
        }
        else if (plus_x == 0 || plus_y == 0)
        {
            if (plus_x == 0)
            {
                if (plus_y > 0)
                {
                    for (int i = 0; i < plus_y; i++)
                    {
                        if (board[original_y + i][original_x] != 0)
                        {
                            cout << "해당 경로가 막혀있습니다.\n";
                            return false;
                        }
                    }
                }
                else
                {
                    for (int i = 0; i > plus_y; i--)
                    {
                        if (board[original_y + i][original_x] != 0)
                        {
                            cout << "해당 경로가 막혀있습니다.\n";
                            return false;
                        }
                    }
                }
            }
            else
            {
                if (plus_x > 0)
                {
                    for (int i = 0; i < plus_x; i++)
                    {
                        if (board[original_y][original_x + i] != 0)
                        {
                            cout << "해당 경로가 막혀있습니다.\n";
                            return false;
                        }
                    }
                }
                else
                {
                    for (int i = 0; i > plus_x; i--)
                    {
                        if (board[original_y][original_x + i] != 0)
                        {
                            cout << "해당 경로가 막혀있습니다.\n";
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}
