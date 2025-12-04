/*
    Problem : https://atcoder.jp/contests/abc395/tasks/abc395_b
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
    ll m = (n/2) + (n&1);
    forn(i,1,n) {
        forn(j,1,n) {
            ll k;
            if(n&1) k = max(abs(m-i), abs(m-j));
            else k = max(abs(m-i+(i>m)), abs(m-j+(j>m)));
            cout << ((k&1) != (m&1) ? '#' : '.');
        }
        cout << endl;
    }
    return 0;
}
