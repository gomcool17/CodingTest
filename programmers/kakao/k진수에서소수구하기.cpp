#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string s, char delimiter) {
    istringstream stt(s);
    vector<string> re;
    string buffer;
    
    while(getline(stt,buffer,delimiter)) re.push_back(buffer);
    
    return re;
}

bool isprime(unsigned long long n) {
    unsigned long long i = 2;
    if(n == 2) return true;
    if(n < 2) return false;
    while((unsigned long long)i*i <= n) {
        if(n % i == 0) return false;
        i++;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s;

    while(n > 0) {
        int N = n % k;
        n /= k;
        s += N + '0';
    }
    reverse(s.begin(), s.end());
    vector<string> v = split(s, '0');
    for(int i=0;i<v.size();i++) {
        if(v[i].size() != 0) {
            unsigned long long num = stoll(v[i]);
            if(isprime(num)) answer++;
        }
    }
    return answer;
}

int main()
{
   cout <<  solution(437674,3) << "\n\n";
   cout << solution(110011,10) << "\n\n";
   cout << solution(999998,9) << "\n\n";
   cout << solution(524287,2) << "\n";
}