/*
    Problem : https://cses.fi/problemset/task/1623
    Author : Baptiste Prévost
    Subjects : recursion, knapsack

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

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> w;

ll solve(int pos, ll left, ll right) {
    if(pos == w.size()) {
        return abs(left-right);
    }
    return min(solve(pos+1, left+w[pos], right), solve(pos+1, left, right+w[pos]));
}

int main() {
    fastIO();

    ll n;
    cin >> n;
    w.resize(n);
    forn(i,0,n-1) cin >> w[i];
    cout << solve(0, 0, 0);
    return 0;
}
