/*
    Problem : https://codeforces.com/contests/2044/problems/C
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

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ll m, a, b, c;
    while(t--) {
        cin >> m >> a >> b >> c;
        ll capa = 2*m;
        ll ans = 0;
        capa -= min(a,m);
        capa -= min(b,m);
        ans += min(a,m) + min(b,m) + min(capa, c);
        cout << ans;
        cout << endl;
    }

    return 0;
}
