/*
    Problem : https://atcoder.jp/contests/abc395/tasks/abc395_d
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
    ll n, q;
    in(n) in(q);
    vll pos(n+1); //for each pigeon, the position its nest
    vll labs(n+1); //for each position, the label of the nest
    vll bals(n+1); //for each nest, its position (inverse of labs)
    forn(i,1,n) {
        pos[i] = i;
        labs[i] = i;
        bals[i] = i;
    }
    int t, a, b;
    while(q--) {
        in(t) in(a);
        if(t==1) {
            in(b)
            pos[a] = bals[b];     
        } else if(t==2) {
            in(b)
            swap(bals[a], bals[b]);
            labs[bals[a]] = a;
            labs[bals[b]] = b;
        } else {
            outln(labs[pos[a]]);
        }

    }

    return 0;
}
