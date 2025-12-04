/*
    Problem : https://codeforces.com/contest/598
    Author : Baptiste Prévost
    Subjects : maths, power

    Idea : Use sum of n and sum of 2^n formula

    Complexity : log(n)
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
        ll ans = n*(n+1) >> 1;
        ll p=2;
        while(p < n) p*=p;
        while(p > n) p >>= 1;
        ans -= 2*(2*p-1);
        cout << ans << endl;
    }

    return 0;
}
