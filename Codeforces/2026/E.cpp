/*
    Problem : https://codeforces.com/contest/2026/problem/E
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
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vector<ll> a(n+1);
        forn(i,1,n) cin >> a[i];

        vector<ll> leftCapacity(61, 1);
        vector<ll> rightCapacity(61, 1);

        vector<bool> lvis(61, false);
        vector<bool> rvis(61, false);
        auto dfs = [&](ll cur, ll prev, ll flow) {
            if(flow == 0) return;
            if(cur == 0 || cur == 61) {
                forn(i,1,60) {
                    if(i == prev) continue;
                    dfs(i, cur, flow)
                }
            } else if(prev == 0) {

            } else {

            }
        };

    }

    return 0;
}
