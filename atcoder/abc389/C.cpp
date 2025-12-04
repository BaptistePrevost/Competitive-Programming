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
    ll q;
    cin >> q;
    ll t, l, k;
    vector<ll> v;
    vector<ll> p;
    v.push_back(0);
    p.push_back(0);
    ll idx = 1;
    ll s = 0;
    forn(i,1,q) {
        cin >> t;
        if(t==1) {
            cin >> l;
            p.push_back(p.back()+l);
            v.push_back(l);
        } else if(t==2) {
            s += v[idx];
            idx++;
        } else {
            cin >> k;
            cout << p[idx+k-2]-s << endl;
        }
    }

    return 0;
}
