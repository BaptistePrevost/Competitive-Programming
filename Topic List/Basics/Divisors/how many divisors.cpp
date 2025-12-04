/*
    Problem : https://vjudge.net/problem/Aizu-ITP1_3_D
    Author : Baptiste Prévost
    Subjects :

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

ll solve(ll n, ll l, ll r) {
  ll ans = 0;
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
        ans += (i >= l && i <= r);
        if (i != n / i && n / i >= l && n / i <= r) ans++;
    }
  }
  return ans;
}

int main() {
    fastIO();
    
    ll a, b, c;
    cin >> a >> b >> c;
    cout << solve(c, a, b) << endl;

    return 0;
}
