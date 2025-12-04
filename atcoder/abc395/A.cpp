/*
    Problem : https://atcoder.jp/contests/abc395/tasks/abc395_a
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
    int t;
    in(t)

    ll a, b;
    in(a)
    bool valid=true;
    forn(i,1,t-1) {
        in(b);
        valid &= (a < b);
        a = b;
    }
    yon(valid);

    return 0;
}
