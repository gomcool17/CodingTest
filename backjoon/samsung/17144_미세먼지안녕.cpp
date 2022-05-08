#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MN 50

int R, C, T;
int up = -1, down = -1;
int board[MN][MN];
struct DIR {
    int y, x;
};

DIR dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};

void fir()
{
    int tmp[MN][MN];

    for(int i=0; i<MN; i++){     
        memset(tmp[i], 0, sizeof(int)*MN); //모든 값 0으로 초기화
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(board[i][j] == 0 || board[i][j] == -1)
                continue;
            
            int cnt = 0;
            for(int d=0;d<4;d++) {
                int y = i + dir[d].y;
                int x = j + dir[d].x;

                if(y >= 0 && x >= 0 && y < R && x < C && board[y][x] != -1) {
                    tmp[y][x] += board[i][j] / 5;
                    cnt += board[i][j]/5;
                }
            }
            tmp[i][j] -= cnt;
        }
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            board[i][j] += tmp[i][j];
        }
    }
}

void move()
{
    int tmp[MN];
    int tmp2[MN];

    for(int i=1;i<C;i++) {
        tmp[i] = board[up][i];
        tmp2[i] = board[down][i];
    }
    board[up][1] = 0, board[down][1] = 0;

    for(int i = 1; i<C - 1;i++) {
        board[up][i+1] = tmp[i];
        board[down][i+1] = tmp2[i];
    }

    int save = tmp[C-1];
    int save2 = tmp2[C-1];

    for(int i = up - 1; i >= 0; i--) {
        int tmp = board[i][C-1];
        board[i][C-1] = save;
        save = tmp;
    }
    
    for(int i=down + 1; i< R; i++) {
        int tmp = board[i][C-1];
        board[i][C-1] = save2;
        save2 = tmp;
    }
    
    for(int i = 0; i<C-1;i++) {
        tmp[i] = board[0][i];
        tmp2[i] = board[R-1][i];
    }
    tmp[C-1] = save;
    tmp2[C-1] = save2;
    for(int i=0;i<C-1;i++) {
        board[0][i] = tmp[i+1];
        board[R-1][i] = tmp2[i+1];
    }

    save = tmp[0];
    save2 = tmp2[0];
    
    for(int i=1;i<up;i++) {
        int tmp = board[i][0];
        board[i][0] = save;
        save = tmp;
    }

    for(int i=R-2;i>down;i--) {
        int tmp = board[i][0];
        board[i][0] = save2;
        save2 = tmp;
    }
}

int result()
{
    int re = 0;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(board[i][j] > 0) 
                re += board[i][j];
        }
    }

    return re;
}
int main()
{
    cin >> R >> C >> T;   
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> board[i][j];
            if(board[i][j] == -1) {
                if(up == -1)
                    up = i;
                else 
                    down = i;
            }
        }
    } 
   
    while(T--) {
        fir();
        move();
    }

    cout << result() << "\n";
}