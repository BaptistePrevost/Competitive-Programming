/*
    Problem : https://codeforces.com/contest/2110/problem/C
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
typedef vector<ll> vll;
typedef vector<bool> vb;

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

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n)
        inv(d, n)
        vll l(n+1), r(n+1);
        vll e(n+1);
        forn(i,1,n) {
            in(l[i]) in(r[i])
            e[i] = max(e[i-1], l[i]);
        }
        bool valid = true;
        ll lowestRight=LLONG_MAX;
        ll h=e[n];
        rofn(i,n,1) {
            lowestRight = min(lowestRight, r[/*
    Problem : https://codeforces.com/contest/2110/problem/C
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
typedef vector<ll> vll;
typedef vector<bool> vb;

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

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n)
        inv(d, n)
        vll l(n+1), r(n+1);
        forn(i,1,n) {
            in(l[i]) in(r[i])
        }

        vll e(n+1);
        ll h=0;
        forn(i,1,n) {
            if(d[i]==-1) {
                e[i]=max(l[i]-h, (ll)0);
                h+=e[i];
            } else {
                e[i]=max(l[i]-h-d[i], (ll)0);
                h+=e[i]+d[i];
            }
        }
        rofn(i,n,1) {
            if(d[i]==-1) {
                if(e[i]>0) {
                    e[i-1] += e[i]-1;
                    d[i]=1;
                } else {
                    d[i]=0;
                }
            } else {
                e[i-1]+=e[i];
            }
        }
        h=0;
        bool valid=true;
        forn(i,1,n) {
            h+=d[i];
            if(h<l[i] || h>r[i]) {
                valid = false;
                break;
            }
        }

        if(!valid) {
            outln(-1);
            continue;
        }

        forn(i,1,n) out(d[i]);
        outln("");
    }

    

    return 0;
}
i]);
            if(h>lowestRight) {
                valid = false;
                break;
            }
            if(d[i]==-1 && e[i]>1) {
                e[i-1] += e[i]-1;
                e[i] = 1;
            } else if(d[i]!=-1 && e[i]>d[i]) {
                e[i-1] += e[i]-d[i];
                e[i] = d[i];
            }
            h-=e[i];
        }
        valid &= h==0;
        if(!valid) {
            outln("-1");
            continue;
        }
        forn(i,1,n) out(e[i]);
        outln("")
    }
    

    return 0;
}
