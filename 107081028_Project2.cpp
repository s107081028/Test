///github:https://github.com/s107081028/Test/commit/e1f8a6e285f61818b942694375b6c87ceff250f5
#include <iostream>
#include <fstream>
using namespace std;
typedef struct _Node{
    int r;
    int c;
}pos;
fstream file;
int row = 0, col = 0, elec = 0, btr = 0, btc = 0, floor = 0, far = 0, farr = 0, farc = 0, bat = 0, now = 0;
pos tour[100000000] = {0};
void calpath(int a, int b, int board[][1002], int sorted[][1002], int cur)
{
    sorted[a][b] = cur;
    if(a - 1 > 0 && board[a - 1][b] == 1 && (sorted[a - 1][b] == 0 || sorted[a - 1][b] > cur + 1)) calpath(a - 1, b, board, sorted, cur + 1);
    if(a + 1 <= row && board[a + 1][b] == 1 && (sorted[a + 1][b] == 0 || sorted[a + 1][b] > cur + 1)) calpath(a + 1, b, board, sorted, cur + 1);
    if(b - 1 > 0 && board[a][b - 1] == 1 && (sorted[a][b - 1] == 0 || sorted[a][b - 1] > cur + 1)) calpath(a, b - 1, board, sorted, cur + 1);
    if(b + 1 <= col && board[a][b + 1] == 1 && (sorted[a][b + 1] == 0 || sorted[a][b + 1] > cur + 1)) calpath(a, b + 1, board, sorted, cur + 1);
}
void home(int a, int b, int board[][1002], int sorted[][1002])
{
    if(a - 1 > 0 && board[a - 1][b] == 10000001){tour[now].r = a - 1; tour[now].c = b; now++;}
    else if(a + 1 <= row && board[a + 1][b] == 10000001){tour[now].r = a + 1; tour[now].c = b; now++;}
    else if(b - 1 > 0 && board[a][b - 1] == 10000001){tour[now].r = a; tour[now].c = b - 1; now++;}
    else if(b + 1 <= col && board[a][b + 1] == 10000001){tour[now].r = a; tour[now].c = b + 1; now++;}
    else if(a - 1 > 0 && board[a - 1][b] == 1 && sorted[a - 1][b] < sorted[a][b]){board[a - 1][b]++; floor--; tour[now].r = a - 1; tour[now].c = b; now++; bat--; home(a - 1, b, board, sorted);}
    else if(a + 1 <= row && board[a + 1][b] == 1 && sorted[a + 1][b] < sorted[a][b]){board[a + 1][b]++; floor--; tour[now].r = a + 1; tour[now].c = b; now++; bat--; home(a + 1, b, board, sorted);}
    else if(b - 1 > 0 && board[a][b - 1] == 1 && sorted[a][b - 1] < sorted[a][b]){board[a][b - 1]++; floor--; tour[now].r = a; tour[now].c = b - 1; now++; bat--; home(a, b - 1, board, sorted);}
    else if(b + 1 <= col && board[a][b + 1] == 1 && sorted[a][b + 1] < sorted[a][b]){board[a][b + 1]++; floor--; tour[now].r = a; tour[now].c = b + 1; now++; bat--; home(a, b + 1, board, sorted);}
    else if(a - 1 > 0 && board[a - 1][b] != 10000000 && sorted[a - 1][b] < sorted[a][b]){tour[now].r = a - 1; tour[now].c = b; now++; bat--; home(a - 1, b, board, sorted);}
    else if(a + 1 <= row && board[a + 1][b] != 10000000&& sorted[a + 1][b] < sorted[a][b]){tour[now].r = a + 1; tour[now].c = b; now++; bat--; home(a + 1, b, board, sorted);}
    else if(b - 1 > 0 && board[a][b - 1] != 10000000 && sorted[a][b - 1] < sorted[a][b]){tour[now].r = a; tour[now].c = b - 1; now++; bat--; home(a, b - 1, board, sorted);}
    else if(b + 1 <= col && board[a][b + 1] != 10000000 && sorted[a][b + 1] < sorted[a][b]){tour[now].r = a; tour[now].c = b + 1; now++; bat--; home(a, b + 1, board, sorted);}
}
void clean(int a, int b, int board[][1002], int sorted[][1002])
{
    if(board[a][b] == 1){ board[a][b]++; floor--;}
    else if(board[a][b] > 1 && board[a][b] != 10000001) board[a][b]++;
    if(bat == sorted[a][b] || floor == 0){ home(a, b, board, sorted); return;}

    int a2 = a - 1, a3 = a + 1, b2 = b - 1, b3 = b + 1;
    if(a - 1 > 0 && board[a - 1][b] == 1 && sorted[a - 1][b] > sorted[a][b]){tour[now].r = a - 1; tour[now].c = b; now++; bat--; clean(a - 1, b, board, sorted);}
    else if(a + 1 <= row && board[a + 1][b] == 1 && sorted[a + 1][b] > sorted[a][b]){tour[now].r = a + 1; tour[now].c = b; now++; bat--; clean(a + 1, b, board, sorted);}
    else if(b - 1 > 0 && board[a][b - 1] == 1 && sorted[a][b - 1] > sorted[a][b]){tour[now].r = a; tour[now].c = b - 1; now++; bat--; clean(a, b - 1, board, sorted);}
    else if(b + 1 <= col && board[a][b + 1] == 1 && sorted[a][b + 1] > sorted[a][b]){tour[now].r = a; tour[now].c = b + 1; now++; bat--; clean(a, b + 1, board, sorted);}
    else if(a - 1 > 0 && board[a - 1][b] == 1 && sorted[a - 1][b] != 0){tour[now].r = a - 1; tour[now].c = b; now++; bat--; clean(a - 1, b, board, sorted);}
    else if(a + 1 <= row && board[a + 1][b] == 1 && sorted[a + 1][b] != 0){tour[now].r = a + 1; tour[now].c = b; now++; bat--; clean(a + 1, b, board, sorted);}
    else if(b - 1 > 0 && board[a][b - 1] == 1 && sorted[a][b - 1] != 0){tour[now].r = a; tour[now].c = b - 1; now++; bat--; clean(a, b - 1, board, sorted);}
    else if(b + 1 <= col && board[a][b + 1] == 1 && sorted[a][b + 1] != 0){tour[now].r = a; tour[now].c = b + 1; now++; bat--; clean(a, b + 1, board, sorted);}
    else if(a2 > 0 && board[a2][b] > 0 && board[a2][b] != 10000000 && board[a2][b] <= board[a3][b] && board[a2][b] <= board[a][b2] && board[a2][b] <= board[a][b3] && sorted[a2][b] > sorted[a][b]){tour[now].r = a - 1; tour[now].c = b; now++; bat--; clean(a - 1, b, board, sorted);}
    else if(a3 <= row && board[a3][b] > 0 && board[a3][b] != 10000000 && board[a3][b] <= board[a2][b] && board[a3][b] <= board[a][b2] && board[a3][b] <= board[a][b3] && sorted[a3][b] > sorted[a][b]){tour[now].r = a + 1; tour[now].c = b; now++; bat--; clean(a + 1, b, board, sorted);}
    else if(b2 > 0 && board[a][b2] > 0 && board[a][b2] != 10000000 && board[a][b2] <= board[a2][b] && board[a][b2] <= board[a3][b] && board[a][b2] <= board[a][b3] && sorted[a][b2] > sorted[a][b]){tour[now].r = a; tour[now].c = b - 1; now++; bat--; clean(a, b - 1, board, sorted);}
    else if(b3 <= col && board[a][b3] > 0 && board[a][b3] != 10000000 && board[a][b3] <= board[a2][b] && board[a][b3] <= board[a3][b] && board[a][b3] <= board[a][b2] && sorted[a][b3] > sorted[a][b]){tour[now].r = a; tour[now].c = b + 1; now++; bat--; clean(a, b + 1, board, sorted);}
    else if(a2 > 0 && board[a2][b] > 0 && board[a2][b] != 10000000 && board[a2][b] <= board[a3][b] && board[a2][b] <= board[a][b2] && board[a2][b] <= board[a][b3] && sorted[a2][b] != 0){tour[now].r = a - 1; tour[now].c = b; now++; bat--; clean(a - 1, b, board, sorted);}
    else if(a3 <= row && board[a3][b] > 0 && board[a3][b] != 10000000 && board[a3][b] <= board[a2][b] && board[a3][b] <= board[a][b2] && board[a3][b] <= board[a][b3] && sorted[a3][b] != 0){tour[now].r = a + 1; tour[now].c = b; now++; bat--; clean(a + 1, b, board, sorted);}
    else if(b2 > 0 && board[a][b2] > 0 && board[a][b2] != 10000000 && board[a][b2] <= board[a2][b] && board[a][b2] <= board[a3][b] && board[a][b2] <= board[a][b3] && sorted[a][b2] != 0){tour[now].r = a; tour[now].c = b - 1; now++; bat--; clean(a, b - 1, board, sorted);}
    else if(b3 <= col && board[a][b3] > 0 && board[a][b3] != 10000000 && board[a][b3] <= board[a2][b] && board[a][b3] <= board[a3][b] && board[a][b3] <= board[a][b2] && sorted[a][b3] != 0){tour[now].r = a; tour[now].c = b + 1; now++; bat--; clean(a, b + 1, board, sorted);}
    else if(a - 1 > 0 && board[a - 1][b] == 10000001){tour[now].r = a - 1; tour[now].c = b; now++; return;}
    else if(a + 1 <= row && board[a + 1][b] == 10000001){tour[now].r = a + 1; tour[now].c = b; now++; return;}
    else if(b - 1 > 0 && board[a][b - 1] == 10000001){tour[now].r = a; tour[now].c = b - 1; now++; return;}
    else if(b + 1 <= col && board[a][b + 1] == 10000001){tour[now].r = a; tour[now].c = b + 1; now++; return;}
}
int main(void)
{
    ifstream infile("floor.data");
    if(!infile) cout<<"can't find file";
    infile>>row>>col>>elec;
    int roww = row + 2;
    int board[roww][1002] = {10000000}, sorted[roww][1002] = {0};
    char temp;
    for(int i = 0; i <= row + 1; i++)
    {
        for(int j = 0; j <= col + 1; j++)
        {
            board[i][j] = 10000000;
            if(i != 0 && i != row+1 && j != 0 && j != col+1)
            {
                infile>>temp;
                if(temp == '1') board[i][j] = 10000000;
                else if(temp == '0')
                {
                    board[i][j] = 1;
                    floor++;
                }
                else if(temp == 'R')
                {
                    board[i][j] = 10000001;
                    btr = i;
                    btc = j;
                }
            }
        }
    }
    calpath(btr, btc, board, sorted, 0);
    tour[now].r = btr;
    tour[now].c = btc;
    now++;
    while(floor)
    {
        bat = elec;
        clean(btr, btc, board, sorted);
    }
    ofstream finalfile("final.path");
    if(!finalfile) cout<<"can't output file";
    finalfile<<now<<endl;
    for(int i = 0; i < now; i++)
    {
        finalfile<<tour[i].r-1<<" "<<tour[i].c-1<<endl;
    }
    finalfile.close();
    return 0;
}
