#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

/*
m = "CCB"
musicinfos = ["03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC"]
*/
int N,Q;
int board[64][64];
vector<int> L;
bool visited[64][64];
struct DIR {
    int y,x;
};

DIR dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};

int re1 = 0, re2= 0;
void rotate(int idx, int jdx, int n)
{
    int tmp[64][64];
    int co[64][64];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            co[i][j] = board[i+idx][j+jdx];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
           // cout << i << " " << j << " " << co[i][j] << "\n";
            tmp[i][j] = co[n-1-j][i];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            board[i + idx][j+jdx] = tmp[i][j];
        }
    }
}

void result(int idx, int jdx)
{
    queue<pair<int,int>> q;
    int cnt = 0;
    q.push({idx,jdx});
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0;d<4;d++) {
            int ny = y+dir[d].y;
            int nx = x+dir[d].x;

            if(ny >= 0 && nx >= 0 && ny < N && nx < N && !visited[ny][nx]) {
                if(board[ny][nx] > 0) {
                    visited[ny][nx] = true;
                    cnt++;
                    q.push({ny,nx});
                }
            }
        }
    }
    re2 = max(cnt, re2);
}
int main()
{
    cin >> N >> Q;
    N = (1 << N);
    
    for(int i=0;i<N;i++)
       for(int j=0;j<N;j++)
            cin >> board[i][j];
    for(int i=0;i<Q;i++) {
        int n; cin>>n;
        n = (1 << n);
        L.push_back(n);
    }
    
    for(int q=0;q<Q;q++) {
        int n = L[q];
        
        for(int i=0;i<N;i+=n) {
            for(int j=0;j<N;j+=n) {
                rotate(i,j,n);
            }
        }

        for(int i=0;i<64;i++)
            memset(visited[i], false, 64);

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                int cnt = 0;
                for(int d=0;d<4;d++) {
                    int y = i + dir[d].y;
                    int x = j + dir[d].x;

                    if(y >= 0 && x >=0 && y < N && x < N) {
                        if(visited[y][x])
                        {
                            if(board[y][x] + 1 > 0)
                                cnt++;
                        }
                        else if(board[y][x]  > 0)
                            cnt++;
                    }
                }
                if(cnt <= 2) {
                    board[i][j]--;
                    visited[i][j] = true;
                }
            }
        }
    }
    
    for(int i=0;i<64;i++)
         memset(visited[i], false, 64);
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(board[i][j] >= 0)
                re1 += board[i][j];
            if(visited[i][j])
                continue;
            result(i,j);
        }
    }

    cout << re1 << "\n";
    cout << re2 << "\n";
}