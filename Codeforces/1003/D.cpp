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
        ll x;
        vector<vector<ll>> a(n+1);
        vector<ll> b(n+1);
        vector<ll> c;
        
        forn(i,1,n) {
            forn(j,1,m) {
                cin >> x;
                a[i].push_back(x);
            }
            c.push_back(i);
        }
        forn(i,1,n) {
            forn(j,1,m) b[i] += a[i][j-1];
        }

        sort(c.begin(), c.end(), [&](const ll &x, const ll &y) {return b[x] > b[y];});

        ll ans = 0;
        forn(i,1,n) {
            forn(j,1,m) {
                ans += a[c[i-1]][j-1] * (n*m - (i-1)*m - j + 1);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
