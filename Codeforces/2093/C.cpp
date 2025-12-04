/*
    Problem : https://codeforces.com/contest/2091/problem/C
    Author : Baptiste Prévost
    Subjects : greedy, permutation

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef long long ll;
typedef unsigned long long ull;
typedef unordered_map<long long, long long, custom_hash> safeMap;
typedef vector<ll> vll;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "Yes" : "No") << endl;
#define in(n) cin >> n;
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}



bool isPrime(ll x) {
    for (ll d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}

int main() {
    fastIO();
    int t; in(t)

    while(t--) {
        ll n, k; in(n) in(k)
        if(k != 1) {
            yon((n==1 && k==2))
        } else {
            yon(isPrime(n));
        }
    }
    

    return 0;
}
