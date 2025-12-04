/*
    Problem : https://www.codechef.com/START159B/problems/SUPER_HERO?tab=statement
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

const ll N = 1e6+9;
ll cnt[N];

void preproc() {
  forn(i,2,N) {
    if(cnt[i]) continue;
    for(ll j=i; j<N; j+=i) {
      ll k = j;
      while(k > 1 && k%i == 0) {
        cnt[j]++;
        k/=i;
      }
    }
  }
}


int main() {
    fastIO();
    preproc();
    int t;
    cin >> t;
    while(t--) {
      ll h, k;
      cin >> h >> k;
      ll a = 1, b = 1;
      while(b*2 <= k) {
        b *= 2;
        a++;
      }
      cout << cnt[h] + a - 1 << endl;
    }

    return 0;
}
