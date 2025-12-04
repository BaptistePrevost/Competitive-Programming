/*
    Problem : https://codeforces.com/contests/2057/problem/B
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

    while(t--) {
        ll n, k;
        ll ans;
        cin >> n >> k;
        ll a;
        safeMap cnt;
        forn(i,1,n) {
            cin >> a;
            cnt[a]++;
        }
        ans = cnt.size();
        vector<ll> freq(n+1);
        for(const auto &kv : cnt) {
            freq[kv.second]++;
        }
        forn(i,1,n) {
            if(i>k) break;
            while(k && freq[i]) {
                freq[i]--;
                k-=i;
                ans--;
            }
        }

        cout << (ans > 0 ? ans : 1) << endl;
    }

    return 0;
}