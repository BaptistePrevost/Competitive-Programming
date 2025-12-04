
/*
    Problem : https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W
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
#define yon(t) cout << (t ? "YES" : "NO") << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool solve(ll cur, const ll &goal) {
    if(cur == goal) return true;
    else if(cur > goal) return false;
    return solve(cur*10, goal) | solve(cur*20, goal);
}

int main() {
    fastIO();

    int t;
    cin >> t;
    ll n;
    while(t--) {
        cin >> n,
        yon(solve(1, n));
    }
    return 0;
}
