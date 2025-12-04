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

    ll n,l, r;
    while(t--) {
        ll ans = 0;
        cin >> n >> l >> r;
        vector<ll> a(n+1);
        forn(i,1,n) cin >> a[i];
        sort(a.begin()+r+1, a.end());
        sort(a.begin()+l, a.begin()+r+1);
        sort(a.begin(), a.begin()+l);
        vector<ll> midPrefix(r-l+2);
        forn(i,1,r-l+1) {
            midPrefix[i] = midPrefix[i-1] + a[r-i+1];
        }
        vector<ll> rightPrefix(n-r+1);
        forn(i,1,n-r) {
            rightPrefix[i] = rightPrefix[i-1] + a[r+i];
        }
        vector<ll> leftPrefix(l);
        forn(i,1,l-1) {
            leftPrefix[i] = leftPrefix[i-1] + a[i];
        }

        ll maxDiff = 0;
        forn(i,1,min(r-l+1, n-r)) {
            maxDiff = max(maxDiff, midPrefix[i]-rightPrefix[i]);
        }
        forn(i,1,min(r-l+1, l-1)) {
            maxDiff = max(maxDiff, midPrefix[i]-leftPrefix[i]);
        }

        cout << midPrefix[r-l+1]-maxDiff << endl;
    }

    return 0;
}
