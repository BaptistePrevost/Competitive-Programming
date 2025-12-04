/*
    Problem : https://atcoder.jp/contests/abc395/tasks/abc395_c
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
typedef vector<long long> vll;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;
#define in(x) cin >> x;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    ll n; in(n)
    vll lst(1e6+9, 0);
    vll mn(1e6+9, n+1);
    
    ll a;
    ll ans = n+1;
    forn(i,1,n) {
        in(a)
        if(lst[a] != 0) {
            mn[a] = min(mn[a], i - lst[a]);
            ans = min(ans, mn[a]);
        }
        lst[a] = i;
    }
    cout << ((ans < n+1) ? ans+1 : -1) << endl;

    return 0;
}
