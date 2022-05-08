#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define EMPTY 0
#define WALL 1
#define INF 987654321

bool visits[100][100];
int small[100][100];
int N;
struct ROBORT {
    int fy, fx; // first
    int sy, sx; // second
    int cnt;
};

struct DIR {
    int y, x;
};

//DIR dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    fill(&small[0][0], &small[N-1][N], INF);
    small[0][0] = 0, small[0][1] = 0;
    queue<ROBORT> q;
    q.push({0,0,0,1,0});
    
    while(!q.empty()) {
        int fy = q.front().fy, fx = q.front().fx;
        int sy = q.front().sy, sx = q.front().sx;
        int cnt = q.front().cnt;
        cout <<"info : " <<  fy << " " << fx << " " <<  sy << " " << sx << " " << cnt << "\n";
        q.pop();
        // 오른쪽
        if(fx+1 < N && sx + 1 < N && board[fy][fx + 1] == EMPTY && board[sy][sx + 1] == EMPTY) {
            cout << "오\n";
            if(fx==sx) {
                if(small[fy][fx+1] > cnt+1){
                    q.push({fy,fx,fy,fx+1,cnt+1});
                    small[fy][fx] = cnt+1;
                   // small[fy][fx+1] = cnt+1;
                }
                if(small[sy][sx+1] > cnt + 1){
                    q.push({sy,sx+1,sy,sx,cnt+1});
                    small[sy][sx] = cnt+1;
                   // small[sy][sx+1] = cnt+1;
                }
            }

            if(small[fy][fx+1] > cnt+1 || small[sy][sx+1] > cnt+1) {
                cout << "right :  \n";
                q.push({fy,fx+1,sy,sx+1,cnt+1});
                small[fy][fx+1] = cnt + 1;
                small[sy][sx+1] = cnt + 1;
            }
        }

        // 왼쪽
        if(fx - 1>= 0 && sx -1 >= 0 && board[fy][fx - 1] == EMPTY && board[sy][sx-1] == EMPTY) {
            cout << "왼\n";
            if(fx==sx) {
                if(small[fy][fx-1] > cnt+1){
                    q.push({fy,fx,fy,fx-1,cnt+1});
                    small[fy][fx] = cnt+1;
                   // small[fy][fx-1] = cnt+1;
                }
                if(small[sy][sx-1] > cnt + 1) {
                    q.push({sy,sx-1,sy,sx,cnt+1});
                    small[sy][sx] = cnt+1;
                  //  small[sy][sx-1] = cnt+1;
                }
            }

            if(small[fy][fx-1] > cnt+1 || small[sy][sx-1] > cnt+1) {
                q.push({fy,fx-1,sy,sx-1,cnt+1});
                small[fy][fx-1] = cnt + 1;
                small[sy][sx-1] = cnt + 1;
            }
        }

        // 위
        if(fy - 1 >=0 && sy-1>=0 && board[fy-1][fx] == EMPTY && board[sy-1][sx] == EMPTY) {
            cout << "위\n";
            if(fy==sy) {
                if(small[fy-1][fx] > cnt+1){
                    q.push({fy,fx,fy-1,fx,cnt+1});
                  //  small[fy-1][fx] = cnt+1;
                    small[fy][fx] = cnt+1;
                }
                if(small[sy-1][sx] > cnt + 1){
                    q.push({sy-1,sx,sy,sx,cnt+1});
                    small[sy][sx] = cnt+1;
                  //  small[sy-1][sx] = cnt+1;
                }
            }

            if(small[fy-1][fx] > cnt+1 || small[sy-1][sx] > cnt+1) {
                q.push({fy-1,fx,sy-1,sx,cnt+1});
                small[fy-1][fx] = cnt + 1;
                small[sy-1][sx] = cnt + 1;
            }
        }

        // 아래
        if(fy+1<N && sy+1<N && board[fy+1][fx] == EMPTY && board[sy+1][sx] == EMPTY) {
            cout << "아래\n";
            if(fy==sy) {
                 if(small[fy+1][fx] > cnt+1){
                    q.push({fy,fx,fy+1,fx,cnt+1});
                    small[fy][fx] = cnt+1;
                  //  small[fy+1][fx] = cnt+1;
                 }
                if(small[sy+1][sx] > cnt + 1) {
                    q.push({sy+1,sx,sy,sx,cnt+1});
                    small[sy][sx] = cnt+1;
                   // small[sy+1][sx] = cnt+1;
                }
            }
            cout << small[fy+1][fx] << " " << small[sy+1][sx] << "\n";
            if(small[fy+1][fx] > cnt+1 || small[sy+1][sx] > cnt+1) {
                q.push({fy+1,fx,sy+1,sx,cnt+1});
                small[fy+1][fx] = cnt + 1;
                small[sy+1][sx] = cnt + 1;
            }
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++){
            if(small[i][j] == INF)
            {
                cout << "- ";
                continue;
            }
            cout << small[i][j] << " ";
        }
        cout << "\n";
    }
    
    return answer;
}

int main() {
   // solution({{0,0,0},{0,0,0},{0,0,0}});
   solution({{0,0,0,1,1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0,0}});

   vector<vector<int>> v = {{0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 0}, {0, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
   solution(v);
   solution({{0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 0}});
}