/*
    Problem : 
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
        vector<ll> a(n+1), b(m+1);
        forn(i,1,n) cin >> a[i];
        forn(i,1,m) cin >> b[i];

        sort(b.begin(), b.end());

        ll prev = LLONG_MIN;
        bool test = true;
        forn(i,1,n) {
            ll left = 0, right = m+1;
            while(right-left>1) {
                ll mid = (left+right)/2;
                if(b[mid] < a[i]+prev) left = mid;
                else right = mid;
            }
            if(right == m+1) {
                if(a[i] < prev) {
                    test = false;
                    break;
                }
                prev = a[i];
            } else {
                if(a[i] >= prev && b[right]-a[i] > a[i]) {
                    prev = a[i];
                } else {
                    prev =b[right]-a[i];
                }
            }
        }

        cout << (test ? "YES" : "NO") << endl;
    }

    return 0;
}
