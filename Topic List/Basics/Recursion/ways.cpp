/*
    Problem : https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Y
    Author : Baptiste Prévost
    Subjects : recursion

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

ll solve(const ll start, const ll end) {
    if(start == end) return 1;
    else if(start > end) return 0;
    return solve(start+1, end) + solve(start+2, end) + solve(start+3, end);
}

int main() {
    fastIO();

    ll s, e;
    cin >> s >> e;
    cout << solve(s,e) << endl;
    return 0;
}
