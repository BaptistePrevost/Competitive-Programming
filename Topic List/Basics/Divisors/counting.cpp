/*
    Problem : https://cses.fi/problemset/task/1713
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

const int N = 1e6+9;
ll primeFactor[N];
void sieve() {
  forn(i,1,N-1) primeFactor[i] = i;
  for(ll p=2; p*p<N; p++) {
    if(primeFactor[p] == p) {
      for(ll n=p*p; n<N; n+=p) {
        if(primeFactor[n] == n) primeFactor[n] = p;
      }
    }
  }
}

ll solve(ll n) {
  ll ans = 1;
  while(n > 1) {
    ll p = primeFactor[n];
    ll k=1;
    while(n%p == 0) {
      k++;
      n/=p;
    }
    ans *= k;
  }
  return ans;
}

int main() {
    fastIO();
    sieve();

    int t;
    cin >> t;
    while(t--) {
      ll n;
      cin >> n;
      cout << solve(n) << endl;
    }

    return 0;
}
