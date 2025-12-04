/*
    Problem : https://codeforces.com/contests/2057/problem/C
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

bool solve(ll &a, ll &b, ll &c, ll &mask, ll &l, ll &r) {
    if(a+mask<=r) {
        if(b+(mask-1)>=l) {
            a += mask;
            if(c+(mask-1)>=l) {
                return true;
            }
            c += mask;
            return true;
        } else if(c+mask <= r) {
            a += mask;
            c += mask;
            return true;
        }
    }
    return false;
}

int main() {
    fastIO();
    int t;
    cin >> t;

    while(t--) {
        ll l, r;
        cin >> l >> r;
        int msb = 31 - __builtin_clz(l ^ r);
        int a = l | ((1<<msb)-1), b = a+1, c = (a==l ? r : l);
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}
