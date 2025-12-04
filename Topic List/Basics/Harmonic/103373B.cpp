/*
    Problem : https://codeforces.com/gym/103373/problem/B
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
//   sort(divs.begin(), divs.end()); //optional
  return divs;
}

int main() {
    fastIO();

    ll n, x;
    vector<ll> ans(1e6+9);
    cin >> n;
    forn(i,1,n) {
        cin >> x;
        if(ans[x] == 0) {
            forv(div, get_divisors(x)) ans[x]+=div;
            ans[x]-=x;
        }
        if(ans[x] < x) {
            cout << "deficient";
        } else if(ans[x] > x) {
            cout << "abundant";
        } else {
            cout << "perfect";
        }
        cout << endl;
    }
    return 0;
}
