/*
    Problem : https://codeforces.com/contest/2091/problem/E
    Author : Baptiste Prévost
    Subjects : dynamic programming, prefix sum

    Idea : The base idea is dynamic programming problem, but with a naive approach, each calculation takes O(d)
    A better approach is to use prefix sum.

    Complexity : O(n*m)
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
typedef unordered_map<ll, pair<ll,ll>, custom_hash> myMap;
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



#define MAX_N 100000
vector<bool> is_prime(MAX_N+1, true);
vll primes;
void sieve_list(ll N) {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= N; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

myMap pf(ll x) {
    myMap ret;
    for(ll prime : primes) {
        if(prime>x) break;
        ll cnt=0;
        ll val=1;
        while(x%prime==0) {
            cnt++;
            val*=prime;
            x/=prime;
        }
        if(cnt) ret[prime] = {cnt,val};
    }
    return ret;
}

int main() {
    fastIO();
    const ll MOD = 998244353;
    int t; in(t)
    sieve_list(MAX_N);

    while(t--) {

        ll n, q; in(n) in(q)
        vll a(n+1);
        forn(i,1,n) in(a[i])
        vector<myMap> pfs(n+1);
        forn(i,1,n) pfs[i] = pf(a[i]);
        ll k, l, r;
        forn(z,1,q) {
            in(k) in(l) in(r)
            myMap kpf = pf(k);
            ll ans=0;
            forn(i,l,r) {
                if(k%a[i]==0) {
                    ll mn=LLONG_MAX;
                    for(auto &pair : pfs[i]) mn = min(mn, kpf[pair.first].first/pair.second.first);
                    k/=pow(a[i], mn);
                    for(auto &pair : pfs[i]) kpf[pair.first].first-=mn;
                }
                ans += k;
            }
            outln(ans);
        }
    }
    

    return 0;
}
