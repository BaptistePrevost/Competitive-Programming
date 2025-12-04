/*
    Problem : https://www.hackerrank.com/challenges/crush/problem
    Author : Baptiste Prévost
    Subjects : prefix sum, range update

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

    ll n, m;
    cin >> n >> m;
    ll a, b, k;
    vector<ll> v(n+2);
    forn(i,1,m) {
        cin >> a >> b >> k;
        v[a] += k;
        v[b+1] -= k;
    }

    ll sum = 0, ans = 0;
    forn(i,1,n) {
        sum = sum+v[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}