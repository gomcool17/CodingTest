#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> v;
    string ss = "";
    for(int i=0;i<s.size();i++) {
        if(s[i] >= '0' && s[i] <= '9')
            ss += s[i];
        if(s[i] == ',') {
            v.push_back(stoi(ss));
            ss = "";
        }
    }
    v.push_back(stoi(ss));
    sort(v.begin(), v.end());
    vector<pair<int,int>> ans;
    
    for(int i=0;i<v.size();i++) {
        int n = upper_bound(v.begin(), v.end(), v[i]) - lower_bound(v.begin(), v.end(), v[i]);
        ans.push_back({n,v[i]});
        i += n - 1;
    }
    sort(ans.begin(), ans.end());
    for(int i=ans.size() - 1;i>= 0;i--) 
        answer.push_back(ans[i].second);
       
    return answer;
}

int main()
{
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    solution(s);
    solution("{{20,111},{111}}");
}