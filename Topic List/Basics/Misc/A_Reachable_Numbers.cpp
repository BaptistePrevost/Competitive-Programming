/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int f(int n) {
    n++;
    while(n%10==0) n/=10;
    return n;
}

int main() {
    map<unsigned int, bool> seen;
    unsigned int n, ans=0;
    cin >> n;
    while(seen.find(n)==seen.end()) {
        seen.insert(make_pair(n, true));
        n = f(n);
        ans++;
    }
    cout << ans;
    return 0;
}