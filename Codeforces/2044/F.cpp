/*
    Problem : https://codeforces.com/contests/2044/problems/A
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct custom_hash { 
    static uint64_t splitmix64(uint64_t x) { 
        x ^= x >> 30; x *= 0xbf58476d1ce4e5b9ULL; 
        x ^= x >> 27; x *= 0x94d049bb133111ebULL; 
        x ^= x >> 31; 
        return x; 
    } 
    size_t operator()(long long x) const { 
        static const uint64_t FIXED_RANDOM =  
        std::chrono::steady_clock::now().time_since_epoch().count(); 
        uint64_t h = (uint64_t)x + FIXED_RANDOM; 
        return (size_t)splitmix64(h); 
    } 
};

int main() {
    fastIO();

    ll n, m, q;
    vector<ll> a, b;
    
    cin >> n >> m >> q;
    a.resize(n+1);
    b.resize(m+1);
    forn(i,1,n) cin >> a[i];
    forn(j,1,m) cin >> b[j];

    ll sa=0;
    forn(i,1,n) sa += a[i];
    ll sb=0;
    forn(j,1,m) sb += b[j];

    unordered_set<ll, custom_hash> lhs;
    forn(i,1,n) lhs.insert(a[i]-sa);
    unordered_set<ll, custom_hash> rhs;
    forn(j,1,m) rhs.insert(b[j]-sb);

    ll x;
    while(q--) {
        cin >> x;
        bool valid=false;
        for(ll i=1; i*i<=abs(x); i++) {
            if(x%i != 0) continue;
            if(lhs.find(i) != lhs.end() && rhs.find(x/i) != rhs.end()) {
                valid=true;
                break;
            }
            if(rhs.find(i) != rhs.end() && lhs.find(x/i) != lhs.end()) {
                valid=true;
                break;
            }
            if(lhs.find(-i) != lhs.end() && rhs.find(-x/i) != rhs.end()) {
                valid=true;
                break;
            }
            if(rhs.find(-i) != rhs.end() && lhs.find(-x/i) != lhs.end()) {
                valid=true;
                break;
            }
        }

        cout << (valid ? "YES" : "NO");
        cout << endl;
    }

    return 0;
}
