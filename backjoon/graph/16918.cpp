#include <iostream>
#include <vector>
#include <queue>

using namespace std;
char arr1[201][201], arr2[201][201], arr3[201][201]; // arr1 = N==1 arr2 : N%4==3, arr3 :N%4==1
bool check1[201][201], check2[201][201];
int R,C,N;

struct DIR {
    int y,x;
};
DIR dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};


int main() {
    cin>>R>>C>>N;
    vector<pair<int,int>> v;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            char a; cin>>a;
            if(a == 'O') v.push_back({i,j});
            arr1[i][j] = a;
            arr2[i][j] = 'O';
            arr3[i][j] = 'O';
        }
    }   

    vector<pair<int,int>> v2;
    for(int i=0;i<v.size();i++) {
        arr2[v[i].first][v[i].second] = '.';
        for(int d=0;d<4;d++) {
            int y = v[i].first + dir[d].y;
            int x = v[i].second + dir[d].x;
            if(y>=0&&x>=0&&y<R&&x<C&&!check1[y][x]) {
                check1[y][x] = true;
                arr2[y][x] = '.';
            }
        }
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(arr2[i][j] == 'O') v2.push_back({i,j});
        }
    }

    for(int i=0;i<v2.size();i++) {
        arr3[v2[i].first][v2[i].second] = '.';
        for(int d=0;d<4;d++) {
            int y = v2[i].first + dir[d].y;
            int x = v2[i].second + dir[d].x;
            if(y>=0&&x>=0&&y<R&&x<C&&!check2[y][x]) {
                check2[y][x] = true;
                arr3[y][x] = '.';
            }
        }
    }

    if(N == 1) {
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) cout << arr1[i][j];
            cout << "\n";
        }
    }
    else if(N%2==0) {
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) cout << "O";
            cout << "\n";
        }
    }
    else if(N%4==3) {
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) cout << arr2[i][j];
            cout << "\n";
        }
    }
    else {
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) cout << arr3[i][j];
            cout << "\n";
        }
    }

}