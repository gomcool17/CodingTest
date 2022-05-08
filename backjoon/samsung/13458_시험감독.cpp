#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    vector<long long> A;
    long long B, C;
    long long re = 0;
    cin >> N;
    for (int i = 0; i < N;i++) {
        long long a;
        cin >> a;
        A.push_back(a);
    }

    cin >> B >> C;

    for (int i = 0; i < N;i++)
    {
        long long s = A[i] - B;
        re++;
        
        if(s > 0)
        {
            re += s / C;
            if(s % C != 0)
                re++;
        }
    }

    cout << re << "\n";
}