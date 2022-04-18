#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

bool id[1000][1000];
int cnt[1000];
int re[1000];
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> m;
    
    for(int i=0;i<id_list.size();i++) {
        m.insert({id_list[i], i});
    }
    
    for(int i=0;i<report.size();i++) {
        string str = report[i];
        istringstream ss(str);
        string buffer;
        vector<string> s;
        while (getline(ss, buffer, ' ')){
            s.push_back(buffer);
        }
        
        int y = m[s[0]], x = m[s[1]];
        if(!id[y][x])   
            cnt[x]++;
        id[y][x] = true;
    }
   
    for(int i=0;i<id_list.size();i++) {
        if(cnt[i] >= k) {
            for(auto iter = m.begin(); iter != m.end(); iter++) {
        
                if(id[iter->second][i]) {
                    re[iter->second]++;
                }
            }
        }
    }
    
    for(int i=0;i<id_list.size();i++) {
       answer.push_back(re[i]);
    }
    
    return answer;
}