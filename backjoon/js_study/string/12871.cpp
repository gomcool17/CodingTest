//https://www.acmicpc.net/problem/12871
//무한 문자열
#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b,a%b) : a;
}

int lcm(int a, int b) {
    return (a*b) / gcd(a,b);
}

int main() {
    string s,f; cin>>s>>f;
    int n = lcm(s.length(), f.length());
    while(s.length() <= n) s+=s;
    while(f.length() <= n) f+=f;
    s = s.substr(0,n);
    f = f.substr(0,n);
    if(s == f) cout << 1 << "\n";
    else cout << 0 << "\n";
}