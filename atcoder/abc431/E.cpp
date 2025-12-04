/*
    Problem : https://atcoder.jp/contests/abc431
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

#define up 0
#define down 1
#define left 2
#define right 3

int main() {
    fastIO();
    inll(t)
    while(t--) {
        inll(h) inll(w)
        std::vector<std::string> grid(h);
        forn(i,0,h-1) {
            in(grid[i])
        }
        // ans[i][j][k] is the minimum number of mirrors to change such that light enters in (i,j) with orientation k
        std::vector<std::vector<std::vector<int>>> ans(h+1, std::vector<std::vector<int>>(w+1, std::vector<int>(5, h*w)));
        
        std::vector<std::pair<std::pair<ll,ll>, ll>> p, q;
        p.push_back({{0,0},3}); //Initially enters in (0,0) directed to the right

        ll m=0;
        bool found = false;
        while(m<h*w) {
            for (auto val : p) {
                ll i = val.first.first;
                ll j = val.first.second;
                ll k = val.second;
                while(i>=0 && i<h && j>=0 && j<w) { //Propagate one beam of light
                    if (ans[i][j][k] < h*w) break;
                    q.push_back({{i,j}, k});
                    ans[i][j][k] = m;
                    if (k==up) {
                        if (grid[i][j] == 'B') {
                            k=left;
                        } else if (grid[i][j] == 'C'){
                            k=right;
                        }
                    } else if (k==down) {
                        if (grid[i][j] == 'B') {
                            k=right;
                        } else if (grid[i][j] == 'C'){
                            k=left;
                        }
                    } else if (k==left) {
                        if (grid[i][j] == 'B') {
                            k=up;
                        } else if (grid[i][j] == 'C'){
                            k=down;
                        }
                    } else {
                        if (grid[i][j] == 'B') {
                            k=down;
                        } else if (grid[i][j] == 'C'){
                            k=up;
                        }
                    }

                    if(k==up) {
                        i-=1;
                    } else if (k==down) {
                        i+=1;
                    } else if (k==left) {
                        j-=1;
                    } else if (k==right) {
                        j+=1;
                    }
                }
                if (i==h-1 && j==w && k==right) {
                    found=true;
                    break;
                }
            }
            if(found) break;

            p.clear();
            for (auto val : q) {
                ll i = val.first.first;
                ll j = val.first.second;
                ll k = val.second;
                if (k==up) {
                    if (grid[i][j] == 'A') {
                        p.push_back({{i,j-1}, left});
                        p.push_back({{i,j+1}, right});

                    } else if (grid[i][j] == 'B') {
                        p.push_back({{i-1,j}, up});
                        p.push_back({{i,j+1}, right});

                    } else {
                        p.push_back({{i-1,j}, up});
                        p.push_back({{i,j-1}, left});
                    }
                } else if (k==down) {
                    if (grid[i][j] == 'A') {
                        p.push_back({{i,j-1}, left});
                        p.push_back({{i,j+1}, right});

                    } else if (grid[i][j] == 'B') {
                        p.push_back({{i+1,j}, down});
                        p.push_back({{i,j-1}, left});
                        
                    } else {
                        p.push_back({{i+1,j}, down});
                        p.push_back({{i,j+1}, right});
                    }
                } else if (k==left) {
                    if (grid[i][j] == 'A') {
                        p.push_back({{i-1,j}, up});
                        p.push_back({{i+1,j}, down});

                    } else if (grid[i][j] == 'B') {
                        p.push_back({{i,j+1}, k});
                        p.push_back({{i+1,j}, down});
                        
                    } else {
                        p.push_back({{i,j+1}, k});
                        p.push_back({{i-1,j}, down});
                    }
                } else if (k==right) {
                    if (grid[i][j] == 'A') {
                        p.push_back({{i-1,j}, up});
                        p.push_back({{i+1,j}, down});

                    } else if (grid[i][j] == 'B') {
                        p.push_back({{i,j+1}, k});
                        p.push_back({{i-1,j}, up});
                        
                    } else {
                        p.push_back({{i,j+1}, k});
                        p.push_back({{i+1,j}, down});
                    }
                }
            }
            q.clear();

            m++;
        }
        outln(m)
    }


}