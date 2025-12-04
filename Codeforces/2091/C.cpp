/*
    Problem : https://codeforces.com/contest/2091/problem/C
    Author : Baptiste Prévost
    Subjects : greedy, permutation

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

int main() {
    fastIO();
    int t; in(t)

    while(t--) {
        ll n; in(n)
        ll a;
        ll ni=0, si=0, mxi=LLONG_MIN, np=0, sp=0, mxp=LLONG_MIN;
        forn(i,1,n) {
            in(a)
            if(a&1) {
                ni++;
                si+=a;
                if(a>mxi) mxi=a;
            } else {
                np++;
                sp+=a;
                if(a>mxp) mxp=a;
            }
        }
        ll ans = max(mxi, mxp);
        if(np > 0 && ni > 0){
            // Try with the largest odd
            ans = max(ans, mxi + (sp - 1) + ((si - mxi) - (ni - 1)) + 1);
            
            // Swap it and try the largest odd
            si -= mxi; sp -= mxp;
            swap(mxi, mxp);
            mxi++; mxp--;
            if(mxp != 0) {
                si += mxi; sp += mxp;
                ans = max(ans, mxi + (sp - 1) + ((si - mxi) - (ni - 1)) + 1);
            }
        } 
        outln(ans)
    }
    

    return 0;
}
