#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> info;
vector<pair<pair<string, int>, pair<string,int>>> v;

bool cmp(pair<pair<string, int>, pair<string,int>> a, pair<pair<string, int>, pair<string,int>> b) {
    if(a.first.first == b.first.first) return a.first.second < b.first.second;
   // else if(a.first.second == b.first.second) return a.second.second < b.second.second; -> stable sort로 바꾸어주고 이 조건 지우니까 맞음
   // 왜지?
    else return a.first.first < b.first.first;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i=0;i<files.size();i++) {
        info[files[i]] = i;
        string name="";
        int n;
        for(int j=0;j<files[i].size();j++) {
            if(files[i][j] >= '0' && files[i][j] <= '9') {
                string N = files[i].substr(j, files[i].size());
                n = stoi(N);
                break;
            }
            name += tolower(files[i][j]);
        }
       // cout << name << " " << n << "\n";
       v.push_back({{name, n}, {files[i],i}});
    }
    
   // sort(v.begin(), v.end(), cmp);
    stable_sort(v.begin(), v.end(), cmp); // sort말고 stable_sort 사용하니까 맞음 sort는 불안정적이라고 한다. 
    for(int i=0;i<v.size();i++) {
        answer.push_back(v[i].second.first);
      //  cout << v[i].second.first <<"\n";
    }
    return answer;
}