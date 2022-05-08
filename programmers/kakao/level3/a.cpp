#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    int rs = rc.size();
    int cs = rc[0].size();
    int m = max(rs, cs);
    cout << rs << " " << m << "\n";
    for(int i=rs;i<m;i++) {
        vector<int> v;
        for(int j=0;j<m;j++) {
            v.push_back(0);
        }
        rc.push_back(v);
    }

    for(int i=0;i<m;i++) {
        for(int j=cs;j<m;j++) {
            rc[i].push_back(0);
        }
    }

     for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
           cout << rc[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i=0;i<operations.size();i++) {
        if(operations[i] == "Rotate") {
            int tmp[100][100];
            for(int j=0;j<m;j++) {
                for(int k=0;k<m;k++) {
                    tmp[j][k] = rc[m-1-k][j];
                }
            }
            for(int j=0;j<m;j++) {
                for(int k=0;k<m;k++) {
                    rc[j][k] = tmp[j][k];
                }
            }
            for(int j=0;j<m;j++) {
                for(int k=0;k<m;k++) {
                    cout << rc[j][k] << " ";
                }
                cout << "\n";
            }
        }
        else {

        }
    }
    return answer;
}

int main()
{
    solution({{1,2,3,4},{5,6,7,8},{9,10,11,12}}, {"ShiftRow", "Rotate", "ShiftRow", "Rotate"});

}