#include <iostream>

using namespace std;

#define ll long long
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    ll a,b,c,d; cin>>a>>b>>c>>d;
    ll mom = b*d;
    ll son = a*d + b*c;
    ll g = gcd(son, mom);
    cout << (son/g) << " " << (mom/g) << "\n";
}