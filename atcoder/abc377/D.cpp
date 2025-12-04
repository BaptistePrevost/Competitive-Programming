/*
    Problem : https://atcoder.jp/contests/abc377/tasks/abc377_d
    Author : Baptiste Prévost
    Subjects : Prefix max, combinatorials

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
#define forv(b,a) for(auto &b : a);

int main() {
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    ll l, r;
    vector<ll> pref(m+1, 1);
    forn(i,1,n) {
        cin >> l >> r;
        pref[r] = max(pref[r], l+1);
    }
    forn(i,1,m) {
        pref[i] = max(pref[i-1], pref[i]);
    }
    forn(i,1,m) {
        ans += i-pref[i]+1;
    }
    cout << ans << endl;

    return 0;
}
