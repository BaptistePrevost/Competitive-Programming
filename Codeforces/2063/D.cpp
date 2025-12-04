/*
    Problem : https://codeforces.com/contests/2057/problem/A
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>

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
    int t;
    cin >> t;

    ll n, m;
    while(t--) {
        cin >> n >> m;
        vector<ll> a(n+1);
        vector<ll> b(m+1);
        forn(i,1,n) cin >> a[i];
        forn(i,1,m) cin >> b[i];

        ll top = 0, bot = 0;
        ll kmax = 2*min(n/3, m/3);
        top += 3*kmax/2; bot += 3*kmax/2;
        if(n-top > m-bot) kmax += min(m-bot, (n-top)/2);
        else kmax += min(n-top, (m-bot)/2);
        cout << kmax << endl;

        forn(i,1,kmax) {

        }
    }

    return 0;
}
