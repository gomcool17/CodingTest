#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

unordered_map<int, int> info, times;
map<int, int> result;
int baseH, baseM, uniH, uniM;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    baseH = fees[0], baseM = fees[1], uniH = fees[2], uniM = fees[3];
    
    for(int i=0;i<records.size();i++) {
        istringstream stt(records[i]);
        string s[2];
        stt >> s[0] >> s[1];
        string h = s[0].substr(0,2);
        string m = s[0].substr(3,2);
        int t = stoi(h) * 60  + stoi(m);
        int carN = stoi(s[1]);

       if(info.find(carN) == info.end()) { // in
            info[carN] = t;
       }
       else { //out
            int use = t - info[carN];
            if(times.find(carN) == times.end()) times[carN] = use;
            else {
                times[carN] += use;
            }
            info.erase(carN);
       } 
    }
    
    for(auto iter = info.begin(); iter != info.end(); iter++) {
        int t = (23*60 + 59) - iter->second;
        times[iter->first] += t;
    }
    
    for(auto iter = times.begin(); iter != times.end(); iter++) {
       int carN = iter->first, finish = iter->second;
       if(finish > baseH) {
           result[carN] = baseM + ceil(((double)(finish - baseH)) / uniH) * uniM; 
       }
        else result[carN] = baseM;
    }
    
    for(auto iter = result.begin(); iter != result.end(); iter++) {
        answer.push_back(iter->second);
    }
    return answer;
}