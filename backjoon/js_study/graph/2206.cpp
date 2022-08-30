// https://www.acmicpc.net/problem/2206
// 벽 부수고 이동하기
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define PUN 1
#define NOPUN 0

struct INFO {
    int y, x;
    int punch;
};

struct DIR { 
    int y,x;
};

DIR dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
int arr[1001][1001];
int len[1001][1001];
bool check[1001][1001][2];

int N,M;

void bfs() {
    queue<INFO> q;
    q.push({0,0,NOPUN});

    while(!q.empty()) {
        INFO info = q.front();
        q.pop();
        cout << info.y << " " << info.x << " " << info.punch << "\n";
        for(int i=0;i<4;i++) {
            int y = info.y + dir[i].y;
            int x = info.x + dir[i].x;

            if(y >= 0 && x >= 0 && y < N && x < M) {
                if(arr[y][x] == 1 && info.punch == NOPUN) {
                    cout << "noPun : " << y << " " << x << "\n";
                    if(len[y][x] > len[info.y][info.x] + 1) {
                        len[y][x] = len[info.y][info.x] + 1;
                        q.push({y,x,PUN});
                        check[y][x][PUN] = true;
                    }
                }
                else if(arr[y][x] == 0 ) {
                    if(len[y][x] > len[info.y][info.x] + 1) {
                        len[y][x] = len[info.y][info.x] + 1;
                        check[y][x][info.punch] = true;
                        q.push({y,x,info.punch});
                    }
                } 
            }
        }
    }
}
int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) {
            char c;
            cin >> c; arr[i][j] = c-'0';
        }
    fill(&len[0][0], &len[N-1][M], 987654321);
    len[0][0] = 0;
    bfs();

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            len[i][j] == 987654321 ? (cout << "-1 ") :(cout << len[i][j] << " ");
        }
        cout << "\n";
    }
    if(len[N-1][M-1] == 987654321) cout << -1 << "\n";
    else cout << len[N-1][M-1] + 1;
   
}