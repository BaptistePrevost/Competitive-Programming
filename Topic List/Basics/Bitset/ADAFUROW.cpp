/*
    Problem : https://www.spoj.com/problems/ADAFUROW/en/
    Author : Baptiste Prévost
    Subjects : bitset

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

int main() {
    fastIO();

    ll q;
    cin >> q;
    char c;
    int x, y;
    const int N = 1e4+9;
    vector<bitset<N>> f(N);
    forn(i,1,q) {
        cin >> c >> x >> y;
        if(c=='+') {
            f[x].set(y);
        } else if(c=='-') {
            f[x].reset(y);
        } else if(c=='v') {
            cout << (f[x]|f[y]).count() << endl;
        } else if(c=='^') {
            cout << (f[x]&f[y]).count() << endl;
        } else if(c=='!') {
            cout << (f[x]^f[y]).count() << endl;
        } else if(c=='\\') {
            cout << (f[x]&~f[y]).count() << endl;
        }
    }
    return 0;
}