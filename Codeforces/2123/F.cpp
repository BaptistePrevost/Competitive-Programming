/*
    Problem : https://codeforces.com/contest/2123/problem/F
    Author : Baptiste Prévost
    Subjects : 

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
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pll> vpll;


#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "Yes" : "No") << endl;
#define in(n) cin >> n;
#define inll(n) ll n; in(n);
#define inv(a,n) vll a(n+1); forn(i,1,n) in(a[i]);
#define inc(c) char c; in(c);
#define ins(s) string s; in(s);
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


#define MAX_N 1e5+7

vll sieve_list(ll N) {
    vector<bool> is_prime(MAX_N+1, true);
    vll primes;
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
 
    return primes;
}

const ll MOD = 1e9+7;
int main() {
    fastIO();
    vll primes=sieve_list(MAX_N);
    int t; in(t)
    
    while(t--) {
        inll(n)
        vll a(n+1);
        vb seen(n+1, false);
        a[1]=1;
        for(int i=primes.size()-1; i>=0; i--) {
            ll p = primes[i];
            if(p>n) continue;
            vll s;
            ll q=p;
            while(q<=n) {
                if(!seen[q]) s.push_back(q);
                q+=p;
            }
            for(int j=0; j<s.size(); j++) {
                seen[s[j]]=true;
                a[s[(j+1)%s.size()]] = s[j];
            }
        }
        forn(i,1,n) out(a[i])
        outln(' ')
    }

    return 0;
}