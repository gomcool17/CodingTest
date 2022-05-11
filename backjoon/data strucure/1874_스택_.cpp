#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

int arr[1000001];

int main() {
    int N;cin>>N;
    for(int i=0;i<N;i++) cin >> arr[i];
    stack<int> st;
    vector<char> re;
    int n = 1;
    int i=0;
    while(1) {
        if(i ==N) break;
        if(n>N && st.top() != arr[i]) {
            cout << "NO\n";
            exit(0);
            break;
        }
        if(!st.empty() && st.top() == arr[i]) {
            st.pop(); re.push_back('-');
            i++;
            continue;
        }
        else {
            st.push(n);re.push_back('+');
            n++;
            continue;
        }
    }
    for(i=0;i<re.size();i++) cout << re[i] << "\n";
}