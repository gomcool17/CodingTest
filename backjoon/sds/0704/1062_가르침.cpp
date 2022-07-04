#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canRead[27];
bool teach[27];
vector<string> v;
int N,K;
int re;

void dfs(int idx, int cnt) {
    if(cnt == K) {
        int c = 0;
        for(int i=0;i<v.size();i++) {
            bool f = true;
            for(int j=0;j<v[i].size();j++) {
                if(!canRead[v[i][j] - 'a']) {
                    f=false;
                    break;
                }
            }
            if(f) c++;
        }

        re = max(re, c);
        return;
    }

    for(int i=idx + 1; i< 26; i++) {
        if(!canRead[i]){
            canRead[i] = true;
            dfs(i, cnt + 1);
            canRead[i] = false;
        }
    }
}
int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        string s; cin>>s;
        string ss = s.substr(4,s.length());
        v.push_back(ss);
        for(int j=0;j<4;j++) {
            v[i].pop_back();
        }
    }
    if(K < 5) cout << 0 << "\n";
    else if(K == 26) cout << N << "\n";
    else {
        K -= 5;
        canRead['a' - 'a'] = true;
        canRead['n' - 'a'] = true;
        canRead['t' - 'a'] = true;
        canRead['i' - 'a'] = true;
        canRead['c' - 'a'] = true;
        dfs(0,0);
        cout << re << "\n";
    }
}