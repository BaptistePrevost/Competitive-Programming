/*
    Problem : 
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

int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = n*n;

    ll i, j;
    unordered_map<ll, unordered_set<ll>> s;
    forn(k,1,m) {
        cin >> i >> j;
        auto handle = [&](ll u, ll v) {
            if(u <= 0 || u > n || v <= 0 || v > n) return;
            if(s.find(u) == s.end()) s[u] = unordered_set<ll>();
            s[u].insert(v);
        };

        handle(i, j);
        handle(i+2, j+1);
        handle(i+1, j+2);
        handle(i-1, j+2);
        handle(i-2, j+1);
        handle(i-2, j-1);
        handle(i-1, j-2);
        handle(i+1, j-2);
        handle(i+2, j-1);
    }

    for(auto p : s) {
        ans -= p.second.size();
    }


    cout << ans << endl;

    return 0;
}
