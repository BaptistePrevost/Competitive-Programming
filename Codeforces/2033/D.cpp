#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

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

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        vector<ll> a(n+1);
        forn(i,1,n) cin >> a[i];

        ll pref = 0;
        unordered_map<ll, ll, custom_hash> m;
        ll ans = 0;
        ll last = -1;
        forn(i,0,n) {
            pref += a[i];
            if(m.find(pref) != m.end() && m[pref] >= last) {
                ans++;
                last = i;
            }
            m[pref] = i;
        }
        
        cout << ans << endl;
    }

    return 0;
}
