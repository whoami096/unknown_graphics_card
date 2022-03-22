#include <iostream>
#include <conio.h>
#include <cstring>
#include <windows.h>
using namespace std;

const int N = 20, M = 20;
char maps[N][M+1] = {
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------",
"--------------------"
};
bool judge()
{
    for(int i=2;i<N-2;i++)
        for(int j=2;j<M-2;j++)
    {
        if(maps[i][j]!='-')
        {
            int ret = 0;
            if(maps[i-1][j]==maps[i][j]&&maps[i-2][j]==maps[i][j]&&maps[i][j]==maps[i+1][j]&&maps[i+2][j]==maps[i][j]) ret = 1;
            else if(maps[i][j]==maps[i][j-1]&&maps[i][j]==maps[i][j-2]&&maps[i][j]==maps[i][j+1]&&maps[i][j]==maps[i][j+2]) ret = 1;
            else if(maps[i][j]==maps[i-1][j-1]&&maps[i][j]==maps[i-2][j-2]&&maps[i][j]==maps[i+1][j+1]&&maps[i][j]==maps[i+2][j+2]) ret = 1;
            if(ret)
            {
                if(maps[i][j]=='@') cout << "Player one won!";
                else cout << "Player two won";
                return true;
            }
        }
    }
    return false;
}
char cmd, op = '-', tgt = '_';
void mov(char cmd, int &x, int &y)
{
    int ret = 0;
    char now;
    if(cmd=='w'&&x>0)
        if(maps[x][y]==tgt) maps[x][y] = op, x--;
        else x--;
    else if(cmd=='s'&&x<N-1)
        if(maps[x][y]==tgt) maps[x][y] = op, x++;
        else x ++;
    else if(cmd=='a'&&y>0)
        if(maps[x][y]==tgt) maps[x][y] = op, y--;
        else y--;
    else if(cmd=='d'&&y<N-1)
        if((maps[x][y]==tgt)) maps[x][y] = op, y++;
        else y ++;
    if(maps[x][y]!=op) ret = 1, now = maps[x][y];
    maps[x][y] = tgt;
    for(int i=0;i<N;i++) puts(maps[i]);
    if(ret) maps[x][y] = now;

}

void down(char chr, int x, int y)
{
    maps[x][y] = chr;
    for(int i=0;i<N;i++) puts(maps[i]);
}

int main()
{

    int x = 0, y = 0;
    int ret = 1;
    maps[x][y] = tgt;
    for(int i=0;i<N;i++) puts(maps[i]);
    while(true)
    {

        cmd = getch();
        system("cls");

        if(cmd==' '&&maps[x][y]=='_')
        {
            char op1;
            if(ret==1)ret=0, op1 = '@' ;
            else ret = 1, op1 = '$';
            down(op1, x, y);
            if(judge()) break;
        }
        else mov(cmd, x, y);
    }
    return 0;
}
