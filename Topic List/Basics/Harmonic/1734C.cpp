/*
    Problem : https://codeforces.com/contest/1734/problem/C
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

int main() {
    fastIO();

    int t;
    cin >> t;
    while(t--) {
      ll n;
      ll ans=0;
      char c;
      cin >> n;
      vector<bool> v(n+1);
      forn(i,1,n) {
        cin >> c;
        v[i] = c=='1';
      }

      vector<ll> cost(n+1, n+1);
      forn(i,1,n) {
        for(ll j=i; j<=n; j+=i) {
          if(v[j]) break;
          cost[j] = min(cost[j], i);
        }
      }
      forn(i,1,n) if(cost[i] < n+1) ans += cost[i];
      cout << ans << endl;
    }

    return 0;
}
