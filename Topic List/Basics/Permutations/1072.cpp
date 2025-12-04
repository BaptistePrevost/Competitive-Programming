/*
    Problem : https://cses.fi/problemset/task/1072
    Author : Baptiste Prévost
    Subjects : combinatorics

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();

    ll n;
    cin >> n;
    
    cout << 0 << endl;
    forn(k,2,n) {        
        cout << k*k*(k*k-1)/2 - 4*(k-1)*(k-2) << endl;
    }
    return 0;
}