/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

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
    ll r;
    cin >> r;

    ll ans = 0;
    forn(i,1,floor(r-0.5)) {
        ans += 4*floor(sqrt(r*r-(i+0.5)*(i+0.5))-0.5);
    }
    ans++; //center piece
    if(r>=2) ans += 4*floor(sqrt(r*r-(0.5)*(0.5))-0.5); //cross
    cout << ans << endl;

    return 0;
}
