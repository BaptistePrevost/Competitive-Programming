/*
    Problem : https://codeforces.com/contest/1350/problem/C
    Author : Baptiste Prévost
    Subjects : harmonic sum

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

ll dfs(ll i, ll n, const vector<ll> &s) {
  ll ans = 1;
  for(ll j=i; j<=n; j+=i) {
    if(s[j] > s[i]) ans = max(ans, 1+dfs(j, n, s));
  }
  return ans;
}


int main() {
    fastIO();

    int t;
    cin >> t;
    while(t--) {
      ll n;
      cin >> n;

      vector<ll> s(n+1);
      forn(i,1,n) cin >> s[i];

      ll ans = 0;
      forn(i,1,n) {
        ans = max(ans, dfs(i,n,s));
      }
      cout << ans << endl;
    }

    return 0;
}
