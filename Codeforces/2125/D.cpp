/*
    Problem : https://codeforces.com/contest/2125/problem/D
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

struct Seg {
    ull left;
    ull right;
    ull a;
    ull b;
};

const ll M = 998244353;

ll mul(ll x, ll y) {
    return x*1LL*y%M;
}

ll add(ll x, ll y) {
    x += y;
    if(x>=M) x-=M;
    if(x<0) x+=M;
    return x;
}

ll binPow(ll x, ll y) {
    ll z=1;
    while(y) {
        if(y&1) z=mul(z,x);
        x = mul(x,x);
        y>>=1;
    }
    return z;
}

int main() {
    fastIO();
    inll(n) inll(m)

    ull topNone=1, botNone=1;
    vector<Seg> segs;
    forn(i,1,n) {
        ull left, right, a, b;
        cin >> left >> right >> a >> b;
        segs.push_back({left, right, a, b});
        topNone = mul(topNone, b-a);
        botNone = mul(botNone, b);
    }
    sort(segs.begin(), segs.end(), [](Seg s, Seg t){ return s.left < t.left; });

    vector<ull> dpTop(n+1, 0); vector<ull> dpBot(n+1, 1);
    dpTop[0] = topNone; dpBot[0] = botNone;
    forv(seg, segs) {
        ull top = mul(dpTop[seg.left-1],mul(seg.a,seg.b));
        ull bot = mul(dpBot[seg.left-1],mul(seg.b,(seg.b-seg.a)));
        ull newTop = add(mul(dpTop[seg.right],bot), mul(dpBot[seg.right],top));
        ull newBot = mul(bot,dpBot[seg.right]);
        dpTop[seg.right] = newTop;
        dpBot[seg.right] = newBot;
    }

    outln(mul(dpTop[n],binPow(dpBot[n],M-2)));

    return 0;
}