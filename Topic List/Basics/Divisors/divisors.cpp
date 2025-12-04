/*
    Problem : https://vjudge.net/problem/Gym-405759K
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
  sort(divs.begin(), divs.end());
  return divs;
}   

int main() {
    fastIO();
    
    ll n, k;
    cin >> n >> k;
    vector<ll> divs = get_divisors(n);
    if(divs.size() < k) cout << "-1" << endl;
    else cout << divs[k-1] << endl;
    return 0;
}
