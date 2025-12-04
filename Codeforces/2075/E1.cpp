/*
    Problem : https://codeforces.com/contests/2057/problem/E1
    Author : Baptiste Prévost
    Subjects : dynamic programming, shortest path, binary search

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

    ll n, m, q;
    ll u, v, w;
    while(t--) {
        cin >> n >> m >> q;
        vector<vector<ll>> adj(n+1);
        vector<vector<ll>> edges(m+1);
        edges[0] = {0,0,0};
        forn(j,1,m) {
            cin >> u >> v >> w;
            edges[j].push_back(u);
            edges[j].push_back(v);
            edges[j].push_back(w);
            adj[u].push_back(j);
            adj[v].push_back(j);
        }


        sort(edges.begin(), edges.end(), [&](const vector<ll> &e1, const vector<ll> &e2) {
            return e1[2] < e2[2];
        });

        vector<vector<vector<ll>>> dp(m+1, vector<vector<ll>>(n+1, vector<ll>(n+1, m)));
        forn(e,1,m) dp[0][edges[e][0]][edges[e][1]] = dp[0][edges[e][1]][edges[e][0]] = 1;
        forn(u,1,n) dp[0][u][u] = 0;
        forn(k,1,n) {
            forn(i,1,n) {
                forn(j,1,n) {
                    dp[0][i][j] = min(dp[0][i][j], dp[0][i][k] + dp[0][k][j]);
                }
            }
        }

        forn(e, 1, m) {
            forn(i,1,n) {
                forn(j,1,n) {
                    dp[e][i][j] = min(
                        dp[e-1][i][j],
                        min(
                            dp[e-1][i][edges[e][0]] + dp[e-1][edges[e][1]][j],
                            dp[e-1][i][edges[e][1]] + dp[e-1][edges[e][0]][j]
                        )
                    );
                }
            }
        }

        ll a, b, k;
        forn(i,1,q) {
            cin >> a >> b >> k;
            
            ll left = 0, right = m+1;
            while(right-left>1) {
                ll mid = (left+right)>>1;
                if(dp[mid][a][b] < k) right = mid;
                else left = mid;
            }
            cout << edges[right][2] << ' ';
        }
        cout << endl;
    }

    return 0;
}
