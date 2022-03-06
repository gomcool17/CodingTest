
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void f(int idx, int jdx, vector<vector<string>> v)
{
    queue<pair<pair<int, int>, bool>> q;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool visit[5][5];
    int cnt[5][5];

    
}

void sol(vector<vector<string>> v)
{
    f(0, 0, v);
}

int main()
{
    vector<vector<string>> v = {{"ABTTT"}, {"TCDET"}, {"TTTFT"}, {"BAHGF"}, {"CDEFG"}};
}