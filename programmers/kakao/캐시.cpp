#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int cache = 0;
    deque<string> dq;

    for(int i=0;i<cities.size();i++) {
        
        for(int j=0;j<cities[i].size();j++)
            cities[i][j] = toupper(cities[i][j]);
        
        dq.push_back(cities[i]);
        bool hit = false;
        int lo=0;
        for(lo; lo<dq.size(); lo++) {
            if(dq[lo] == cities[i]) {
                hit = true;
                break;
            }
        }

        if(hit) {
            dq.erase(dq.begin() + lo);
            answer += 1;
        }
        else {
            answer += 5;
            if(dq.size() > cacheSize) dq.pop_front();
        }
    }
    return answer;
}