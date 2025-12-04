/*
    Problem : https://atcoder.jp/contests/abc424
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

const ll INF = 100;

int main() {
    fastIO();
    inll(t)
    while(t--) {
        inll(h) inll(w)
        vector<string> grid(h);
        forn(i,0,h-1) {
            in(grid[i]);
        }
        
        ll p = 1<<w;
        vector<vb> compatible(p, vb(p, true));
        forn(i,0,p) {
            forn(j,0,p) {
                forn(k,0,w-1) {
                    if(((i>>k)&3)==3 && ((j>>k)&3)==3) {
                        compatible[i][j] = false;
                        break;
                    }
                }
            }
        }
        vll dp(p, INF);
        dp[0]=0;
        forn(i,0,h-1) {
            ll state = 0;
            forn(j,0,w-1) {
                if(grid[i][j]=='#') state+=(1<<j);
            }
            vll qp(p, INF);
            forn(j,0,p-1) {
                if ((j|state) != state) continue;
                ll cost=0;
                forn(l,0,w-1) {
                    cost += ((j^state)>>l)&1;
                }
                forn(jj,0,p-1) {
                    if(!compatible[j][jj]) continue;
                    qp[j] = min(qp[j], dp[jj]+cost);
                }
            }
            dp=qp;
        }
        ll ans = INF;
        forn(i,0,p-1) {
            ans = min(ans, dp[i]);
        }
        outln(ans);
    }
    return 0;
}