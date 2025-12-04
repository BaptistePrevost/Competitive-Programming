/*
    Problem : https://vjudge.net/problem/CSES-2165
    Author : Baptiste Prévost
    Subjects : recursion, hanoi

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

vector<pair<int, int>> sol;
void hanoi(ll sz, int start, int mid, int end) {
    if(sz==1) {
        sol.push_back(make_pair(start, end));
        return;
    }
    hanoi(sz-1, start, end, mid);
    sol.push_back(make_pair(start, end));
    hanoi(sz-1, mid, start, end);
}

int main() {
    fastIO();

    ll n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << sol.size() << endl;
    for(const pair<int, int> &p : sol) {
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
