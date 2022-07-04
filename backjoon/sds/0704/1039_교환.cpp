#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string num; 
    int K;
    cin >> num >> K;

    queue<string> q;
    q.push(num);
    
    for(int k=0;k<K;k++) {
        set<string> se;

        int qSize = q.size();
        for(int i = 0; i<qSize; i++) {
            string number = q.front();
            q.pop();

            if(se.count(number)) continue;
            se.insert(number);

            for(int j = 0; j<number.size() - 1;j++) {
                for(int h = j+1; h < number.size(); h++) {
                    if(j==0 && number[j] == '0') continue;
                    string save = number;
                    char tmp = number[j];
                    number[j] = number[h];
                    number[h] = tmp;
                    q.push(number);
                    number=save;
                }
            }
        }
    }

    string re = "0";
    while(!q.empty()) {
        re = max(re, q.front());
        q.pop();
    }

    if(re[0] == '0') cout << "-1";
    else cout << re << "\n";
}