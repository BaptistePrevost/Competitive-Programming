/*
    Problem : https://atcoder.jp/contests/abc348/tasks/abc348_f
    Author : Baptiste Prévost
    Subjects : bitset optimization

    Idea :

    Complexity : O(N*M*)
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

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n+1, vector<ll>(m+1));
    forn(i,1,n) {
        forn(j,1,m) cin >> a[i][j];
    }


    vector<bitset<2001>> u(1000);
    vector<bitset<2001>> v(n+1);
    forn(j,1,m) {
        forn(i,1,n) u[a[i][j]].set(i);
        forn(i,1,n) v[i] ^= u[a[i][j]];
        forn(i,1,n) u[a[i][j]].reset(i);
    }

    ll ans=0;
    forn(i,1,n) ans += v[i].count();
    if(m&1) ans-=n;

    cout << ans/2 << endl;
    return 0;
}