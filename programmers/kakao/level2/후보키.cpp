#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

// 나중에 다시 풀기@@@ -> 다시 풀어서 맞춤!
set<string> attributes, minimal;
bool check[8];
bool used[8];
vector<vector<int>> v;
int re;

bool cmp(vector<int> v1, vector<int> v2) {
    return (v1.size() < v2.size());
}

bool check_can(vector<vector<string>> relation, set<string> &s) {
    for(int i=0;i<relation.size();i++) {
        string str = "";
        for(int j=0;j<relation[i].size();j++) {
            if(check[j]) {
                str += relation[i][j];
            }
            if(minimal.count(str)) {
                if(!used[j])
                    continue;
                return false;
            }
        }
        if(attributes.count(str))
            return false;
        else attributes.insert(str);
        s.insert(str);
        if(str.size() == 0) return false;
    }
   // if(s.size() < relation.size()) return false;
    return true;
}

void candidate(int idx, vector<vector<string>>  relation, int N) {
    set<string> s;
    if(idx == N)
        return;
    
    check[idx] = true;
    if(check_can(relation,s)){ 
        vector<int> res;    
        for(int i=0;i<N;i++)  if(check[i])  res.push_back(i);
        
        v.push_back(res);
        re++;
    }
    attributes.clear();
    candidate(idx + 1, relation, N);
    
    check[idx] = false;
    candidate(idx+1, relation, N);
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int column = relation[0].size();
    //minimal.insert({"infinfinfifnfifnifnifnfi"});
    candidate(0, relation, column);

    sort(v.begin(), v.end(), cmp);
   
    re = v.size();
    set<int> not_c;
    for(int i=0;i<v.size();i++) {
        if(not_c.count(i) == 1) continue;
        for(int j= i+1;j<v.size();j++) {
            int cnt = 0;
            for(int a = 0; a<v[i].size(); a++) 
                for(int b=0;b<v[j].size();b++) if(v[i][a] == v[j][b]) cnt++;
      
            if(cnt == v[i].size()) not_c.insert(j);
        }
    }
   
    answer = v.size() - not_c.size();
    cout << answer << "\n";
    return answer;
}