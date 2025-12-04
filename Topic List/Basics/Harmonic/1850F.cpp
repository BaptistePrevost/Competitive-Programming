/*
    Problem : https://codeforces.com/contest/1850/problem/F
    Author : Baptiste Prévost
    Subjects :harmonic sum

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

    int t;
    cin >> t;
    while(t--) {
      ll n, w;
      cin >> n;
      vector<ll> ws(n+1);
      vector<ll> cnt(n+1);
      forn(i,1,n) {
        cin >> w;
        if(w <= n) ws[w]++;
      }
      forn(i,1,n) {
        for(ll x=i; x<=n; x+=i) cnt[x] += ws[i];
      }
      ll mx=0;
      forn(i,1,n) mx = max(mx, cnt[i]);
      cout << mx << endl;
    }

    return 0;
}
