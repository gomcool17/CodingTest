#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> dic_a, save;

vector<int> solution(string msg) {
    vector<int> answer;
    for (char i = 'A'; i <= 'Z'; i++) {
        string a = ""; a += i;
        dic_a[a] = i - 'A' + 1;
    }

    for (int i = 0; i < msg.size();) {
        string str = ""; str += msg[i];
        string save="";
        for (int j = i + 1; j <= msg.size(); j++) {
            if (dic_a.find(str) != dic_a.end()) {
                if (j == msg.size()) {
                    answer.push_back(dic_a[str]);
                    i++;
                    break;
                }
                save = str;
                str += msg[j];
                i++;
            }
            else {
                int n = dic_a.size() + 1;
                dic_a[str] = n;
                answer.push_back(dic_a[save]);
                break;
            }
        }
    }

    return answer;
}