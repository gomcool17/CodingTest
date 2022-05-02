#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> g[18];
int re = 0;
void dfs(int now, int sheep, int wolf, vector<int> next, vector<int> info) {
    if(info[now]) wolf++;
    else sheep++;
    cout << now << " " << sheep << " " << wolf << "\n";
    re = max(re, sheep);
    if(wolf>=sheep) return;
    
    for(int i=0;i<next.size();i++) {
        vector<int> n = next;
        n.erase(n.begin() + i);
        
        for(int j=0;j<g[next[i]].size();j++) {
            n.push_back(g[next[i]][j]);
        }
        dfs(next[i], sheep, wolf, n, info);
    }
    
    return;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    for(int i=0;i<edges.size();i++) {
       g[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int> next;
    for(int i=0;i<g[0].size();i++) next.push_back(g[0][i]);
    cout << next[0] << " " << next[1];
    dfs(0,0,0,next,info);
    answer = re;
    return answer;
}
int main()
{
    vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges = {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};

    solution(info, edges);
}