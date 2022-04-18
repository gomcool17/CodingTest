#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define DO 3
#define INF 987654321

int N,M;
int board[50][50];
vector<pair<int,int>> virus;

bool virus_check[10];
bool flag;
int re = INF;
struct DIR {
    int y,x;
};

DIR dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
void virus_on()
{
    queue<pair<int,int>> q;
    int map[50][50];
    fill(map[0], map[0] + 50 * 50, INF);

    for(int i=0;i<virus.size();i++) {
        if(virus_check[i]) {
            board[virus[i].first][virus[i].second] = DO;
            q.push({virus[i].first, virus[i].second});
            map[virus[i].first][virus[i].second] = 0;
        }
    }

    while(!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        for(int d=0;d<4;d++) {
            int y = ny + dir[d].y;
            int x = nx + dir[d].x;

            if(y >= 0 && x >= 0 && y < N && x < N && (board[y][x] == EMPTY || board[y][x] == VIRUS)) {
                if(map[ny][nx] + 1 < map[y][x]) {
                    q.push({y,x});
                    map[y][x] = map[ny][nx] + 1;
                }
            }
        }
    }

    int m = 0;
    bool no_e = true;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) { 
            if(map[i][j] == INF && board[i][j] == EMPTY) {
                no_e = false;
                break;
            }
            else if(board[i][j] == EMPTY && map[i][j] != INF) {
                m = max(m, map[i][j]);
            }
        }
    }

    if(no_e) {
        re = min(re, m);
    }

    for(int i=0;i<virus.size();i++) {
        if(virus_check[i]) {
            board[virus[i].first][virus[i].second] = VIRUS;
        }
    }
}
void sol(int idx, int cnt)
{
    if(cnt == M) {
        virus_on();
        return;
    }
    for(int i=idx;i<virus.size();i++) {
        if(!virus_check[i])  {
            virus_check[i] = true;
            sol(i + 1, cnt + 1);
            virus_check[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
            if(board[i][j] == VIRUS)
                virus.push_back({i,j});
        }
    }

    sol(0,0);
    if(re == INF)
        cout << "-1\n";
    else 
        cout << re << "\n";
}