/*
    Problem : https://codeforces.com/contest/2033/problem/E
    Author : Baptiste Prévost
    Subjects : permutation, binary exponentiation

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
    int t;
    cin >> t;
    ll n;

    while(t--) {
        cin >> n;
        vector<ll> p(n+1);
        forn(i,1,n) cin >> p[i];

        ll ans = 0;

        vector<bool> vis(n+1,false);
        forn(i,1,n) {
            ll cur = p[i];
            ll sz = 0;
            while(!vis[cur]) {
                vis[cur] = true;
                cur = p[cur];
                sz++;
            }
            ans += (sz-1)/2;
        }
        
        cout << ans << endl;
    }

    return 0;
}
