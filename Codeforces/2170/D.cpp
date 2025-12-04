/*
    Problem : https://codeforces.com/contest/2170/problem/E
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

ll query(ll l, ll r) {
    out('?') out(l) outln(r)
    inll(ret)
    return ret;
}

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n) inll(q)
        std::vector<char> s(n+1);
        forn(i,1,n) in(s[i]);

        vll cost(n+1, 0);
        ll sm = 0;
        forn(i,1,n) {
            if(s[i] != '?') {
                if(s[i]=='I') sm+=1;
                if(s[i]=='V') sm+=5;
                if(s[i]=='X') sm+=10;
                continue;
            }
            if(i>1 && (s[i-1] == 'I' || s[i-1] == '?')) cost[i]-=2;
            if(i<n-1 && (s[i+1] == 'V' || s[i+1] == 'X')) cost[i]+=2;
        }
        vll gains;
        forn(i,1,n) {
            if(s[i] != '?') continue;
            if(cost[i]>=0) continue;
            if(i>1 && (s[i-1] == 'I' || s[i-1] == '?')) {
                s[i] = '!';
                gains.push_back(2);
            }
        }
        forn(i,1,n) {
            if(s[i] != '?') continue;
            if(i<n-1 && (s[i+1] == 'V' || s[i+1] == 'X' || s[i+1] == '!')) {
                gains.push_back(-2);
            } else {
                gains.push_back(0);
            }
        }

        vll pref(gains.size(), gains[0]);
        forn(i,1,gains.size()-1) pref[i] = pref[i-1] + gains[i];
        
        forn(i,1,q) {
            inll(a) inll(b) inll(c)
            b = min(b, max((ll)0, n-c));
            a = min(a, max((ll)0, n-c-b));

            ll ans = sm+a*10+b*5+c+pref[a+b];
            outln(ans)
        }

    }

    return 0;
}