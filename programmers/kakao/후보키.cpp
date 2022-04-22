#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

// 나중에 다시 풀기@@@
set<string> attributes, minimal;
bool check[8];
bool used[8];
int re;
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
    }
    return true;
}

void candidate(int idx, vector<vector<string>>  relation, int N) {
    set<string> s;
    if(idx == N)
        return;

    check[idx] = true;
    if(check_can(relation,s)){     
        for(int i=0;i<N;i++) {
            cout << check[i] << " ";
            if(check[i]) used[i] = true;
        }
        cout << "\n";
        re++;
        if(!unique(relation, s)) re--;

        for(auto it = s.begin(); it != s.end(); it++) {
            minimal.insert(*it);
            cout << *it << "\n";
        }
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
     
    answer= re;
    cout << answer << "\n";
    return answer;
}
int main()
{
   // vector<vector<string>> relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};

  //  vector<vector<string>> relation = {{"100", "100", "ryan", "music", "2"}, {"200", "200", "apeach", "math", "2"}, {"300", "300", "tube", "computer", "3"}, {"400", "400", "con", "computer", "4"}, {"500", "500", "muzi", "music", "3"}, {"600", "600", "apeach", "music", "2"}};
    vector<vector<string>> relation = { {"a","1","aaa","c","ng"},{"a","1","bbb","e","g"},{"c","1","aaa","d","ng"},{"d","2","bbb","d","ng"}};
    solution(relation);
}