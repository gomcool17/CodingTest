#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 98765432;
vector<pair<int,int>> g[20000];
int dist[201][201];
int arr[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    fill(&dist[0][0], &dist[200][201],INF);
    fill(&arr[0][0], &arr[200][201], INF);

    for(int i=0;i<fares.size();i++) {
        arr[fares[i][0]][fares[i][1]] = fares[i][2];
        arr[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for(int i=1;i<=n;i++) {
        arr[i][i] = 0;
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    
    answer = arr[s][a] + arr[s][b];
    for(int i=1;i<=n;i++) {
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    }
    
    return answer;
}