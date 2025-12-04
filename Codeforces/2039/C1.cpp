/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ll x, m;
    while(t--) {
        cin >> x >> m;

        unordered_set<ll> ys;

        for(ll d=1; d<x; d++) {
            ll y = d^x;
            if((x%d == 0 || y%d == 0) && (y != x && y >= 1 && y <= m) ) ys.insert(y);
        }
        
        cout << ys.size() << endl;
    }

    return 0;
}
