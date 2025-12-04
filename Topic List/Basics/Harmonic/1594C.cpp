/*
    Problem : https://codeforces.com/contest/1594/problem/C
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

vector<ll> get_divisors(ll n) {
  vector<ll> divs;
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != n / i) {
        divs.push_back(n / i);
      }
    }
  }
  sort(divs.begin(), divs.end()); //optional
  return divs;
}

int main() {
    fastIO();

    int t;
    cin >> t;
    while(t--) {
      ll n;
      char c;
      cin >> n;
      cin >> c;

      char d;
      vector<bool> v(n+1);
      bool distinct = false;
      forn(i,1,n) {
        cin >> d;
        if(d != c) {
          for(ll div : get_divisors(i)) v[div] = true;
          distinct = true;
        }
      }

      if(!distinct) {
        cout << 0 << endl;
      } else {
        ll found = 0;
        forn(i,1,n) {
          if(!v[i]) {
            found = i;
            break;
          }
        }
        
        if(found > 0) {
          cout << 1 << endl;
          cout << found << endl;
        } else {
          cout << 2 << endl;
          cout << n-1 << " " << n << endl;
        }
      }
    }

    return 0;
}
