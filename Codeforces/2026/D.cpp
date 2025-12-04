/*
    Problem : https://codeforces.com/contest/2026/problem/D
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
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    forn(i,1,n) cin >> a[i];
    
    vector<ll> pref(n+1);
    forn(i,1,n) pref[i] = pref[i-1] + a[i];
    
    vector<ll> qref(n+1);
    forn(i,1,n) qref[i] = qref[i-1] + pref[i];

    vector<ll> blocks(n+1);
    blocks[n] = a[n];
    rofn(i,n-1,1) {
        blocks[i] = blocks[i+1] + (n-i+1)*a[i];
    }

    vector<ll> bref(n+1);
    forn(i,1,n) bref[i] = bref[i-1] + blocks[i];

    vector<ll> indices = {0};
    ll index = 0;
    rofn(i,n,1) {
        index += i;
        indices.push_back(index);
    }

    ll q;
    cin >> q;
    ll r, l;
    while(q--) {
        cin >> l >> r;
        l--;

        auto solve = [&](ll x) {
            ll left = -1;
            ll right = indices.size()-1;
            ll mid;
            while(right-left>1) {
                mid = (left+right)>>1;
                if(indices[mid] > x) right = mid;
                else left = mid;
            }

            ll start = left+1;
            ll end = left+x-indices[left];

            return bref[left] + qref[end] - qref[start-1] - (end - start + 1)*pref[start-1];
        };

        cout << solve(r) - solve(l) << endl;

    }

    return 0;
}
