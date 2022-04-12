#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321;

int N,M,K;
int energy[11][11];
int board[11][11];
vector<int> info[11][11];
int cnt = 0;

struct DIR {
    int y, x;
};

DIR dir[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void sortTrees()
{
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N;j++) {
            if(info[i][j].size() == 0)
                continue;
            sort(info[i][j].begin(), info[i][j].end());
        }
    }
}

void springtosummer()
{
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(info[i][j].size() == 0)
                continue;
            int dead = 0;
            vector<int> tmp;
            sort(info[i][j].begin(), info[i][j].end());
            for(int k=0;k<info[i][j].size();k++) {
                int age = info[i][j][k];
                
                if(age > energy[i][j]) {
                    dead += age/2;
                }
                else {
                    energy[i][j] -= age;
                   // cout << energy[i][j] << "\n";
                    tmp.push_back(age+1);
                }
            }

            info[i][j].clear();
            for(int k=0;k<tmp.size();k++) {
                info[i][j].push_back(tmp[k]);
            }
        
            energy[i][j] += dead;
        }
    }
    
}

void fall()
{
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<= N;j++) {
            if(info[i][j].size() == 0)
                continue;

            for(int k=0;k<info[i][j].size();k++) {
                
                if(info[i][j][k] % 5 == 0) {
                    for(int d = 0; d < 8 ; d++) {
                        int y = i + dir[d].y;
                        int x = j + dir[d].x;

                        if(y >= 1 && x >= 1 && y <= N && x <= N) {
                            info[y][x].push_back(1);
                        }
                    }
                }
            }
            
        }
    }
}

void winter()
{
    for(int i=1;i<=10;i++) {
        for(int j=1;j<=10;j++) {
            energy[i][j] += board[i][j];
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) 
        for(int j=1;j<=N;j++) {
            cin >> board[i][j];
            energy[i][j] = 5;
        }
    
    for(int i=0;i<M;i++) {
        int y, x, age; cin >> y >> x >> age;
        info[y][x].push_back(age);
    }
   
    while(K--) {
        springtosummer();
        fall();
        winter(); 
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cnt += info[i][j].size();
        }
    }

    cout << cnt << "\n";
}