#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int M, N;
bool check[30][30];
bool finish;
struct DIR {
    int y, x;
};

DIR dir[4][3] = {{{0,1},{1,0},{1,1}}, {{0,1}, {-1,1},{-1,0}}, {{0,-1},{-1,0},{-1,-1}}, {{0,-1},{-1,0},{-1,-1}}};
int check_c(int i, int j, vector<string> board, bool &flag) {
    int cnt = 0;
   
    int y = i;
    int x = j;
    char c = board[y][x];
    for(int d=0;d<4;d++) {
        int ny1 = y + dir[d][0].y, ny2 = y+dir[d][1].y, ny3 = y+dir[d][2].y;
        int nx1 = x + dir[d][0].x, nx2 = x+dir[d][1].x, nx3 = x+dir[d][2].x;

        if(ny1 >= 0 && ny2 >=0 && ny3>=0 && ny1 < N && ny2 < N && ny3 < N && nx1 >= 0 && nx2 >=0 && nx3>=0 && nx1 < M && nx2 < M && nx3 < M) {
            if(c==board[ny1][nx1] && c==board[ny2][nx2] &&c==board[ny3][nx3]) {
                if(!check[ny1][nx1]) {
                    check[ny1][nx1] = true;
                    cnt++;
                }
                if(!check[ny2][nx2]) {
                    check[ny2][nx2] = true;
                    cnt++;
                }
                if(!check[ny3][nx3]) {
                    check[ny3][nx3] = true;
                    cnt++;
                }
                if(!check[y][x]) {
                    check[y][x] = true;
                    cnt++;
                }
                flag = true;
                break;
            }
        }
    }
    return cnt;
}

int play(vector<string> &board) {
    memset(&check[0], false, sizeof(bool) * 30*30);
    int cnt = 0;
    bool flag= false;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(board[i][j] == '-') continue;
            if(!check[i][j]) {
                cnt += check_c(i,j, board, flag);
            }
        }
    }
    
    if(flag) {
        for(int j=0;j<M;j++) {
            string tmp="";
            bool f = false; 
            int s=N;
            int c = 0;
            for(int i=0;i<N;i++) {
                if(check[i][j] || board[i][j] == '-') continue;
                else tmp += board[i][j];
            }

            int n = tmp.size();
            for(int i=n ;i<N;i++) {
                tmp = '-'+tmp;
            }
            for(int i=0;i<N;i++)  board[i][j] = tmp[i];
        }
    }
    else finish = true;
    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    M = n, N=m;

    while(!finish) {
        answer += play(board);
    }
    
    return answer;
}

int main()
{
    //vector<string> board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
   // vector<string> board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    vector<string> board = {"CCZXZ","CCZXZ","XXZXZ","AAZAA","AAAAA","ZAAXX"};

    solution(6,5,board);
}