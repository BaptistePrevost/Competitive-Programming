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
    inll(H) inll(W);
    std::vector<std::string> grid(H+1);
    forn(i,1,H) {
        in(grid[i]);
    }

    vector<vb> visited(H+1, vb(W+1, false));
    vector<vector<int>> neighbors(H+1, vector<int>(W+1, 0));
    vector<pair<ll,ll>> bfs;
    forn(i,1,H) {
        forn(j,0,W-1) {
            if (grid[i][j] == '.') continue;
            if (i > 1) neighbors[i-1][j]++;
            if (i < H) neighbors[i+1][j]++;
            if (j > 0) neighbors[i][j-1]++;
            if (j < W-1) neighbors[i][j+1]++;
        }
    }

    ll ans = 0;
    forn(i,1,H) {
        forn(j,0,W-1) {
            if (grid[i][j] == '#') {
                ans++;
                visited[i][j] = true;
            } else if (neighbors[i][j] == 1) {
                bfs.push_back({i,j});
                visited[i][j] = true;
            }
        }
    }


    while (!bfs.empty()) {
        vector<pair<ll,ll>> efs;
        for(auto [i,j] : bfs) {
            grid[i][j] = '#';
            ans++;
            visited[i][j] = true;
            if (i > 1) {
                neighbors[i-1][j]++;
            }
            if (i < H) {
                neighbors[i+1][j]++;
            }
            if (j > 0) {
                neighbors[i][j-1]++;
            }
            if (j < W-1) {
                neighbors[i][j+1]++;
            }
        }
        for(auto [i,j] : bfs) {
            if (i > 1) {
                if (neighbors[i-1][j] == 1 && !visited[i-1][j]) {
                    efs.push_back({i-1,j});
                    visited[i-1][j] = true;
                }
            }
            if (i < H) {
                if (neighbors[i+1][j] == 1 && !visited[i+1][j]) {
                    efs.push_back({i+1,j});
                    visited[i+1][j] = true;
                }
            }
            if (j > 0) {
                if (neighbors[i][j-1] == 1 && !visited[i][j-1]) {
                    efs.push_back({i,j-1});
                    visited[i][j-1] = true;
                }
            }
            if (j < W-1) {
                if (neighbors[i][j+1] == 1 && !visited[i][j+1]) {
                    efs.push_back({i,j+1});
                    visited[i][j+1] = true;
                }
            }
        }
        bfs = efs;
    }

    outln(ans)


    return 0;
}