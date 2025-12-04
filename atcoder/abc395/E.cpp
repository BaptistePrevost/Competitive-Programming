/*
    Problem : https://atcoder.jp/contests/abc395/tasks/abc395_e
    Author : Baptiste Prévost
    Subjects : shortest paths, dijkstra 2D

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;
#define in(x) cin >> x;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    ll n, m, x;
    in(n) in(m) in(x);
    
    vector<vll> adj(n+1);
    vector<vll> jda(n+1);
    ll u, v;
    forn(i,1,m) {
        in(u) in(v)
        adj[u].push_back(v);
        jda[v].push_back(u);
    }
    
    deque<pair<ll,bool>> q;
    vector<vll> dist(n+1, vll(2, (x+1)*m));
    q.push_front({1, true});
    dist[1][true] = 0;
    
    while(!q.empty()) {
        ll u = q.front().first;
        ll p = q.front().second;
        q.pop_front();
        
        vll &neigh = (p ? adj[u] : jda[u]);
        forv(v, neigh) {
            if(dist[u][p] + 1 < dist[v][p]) {
                dist[v][p] = dist[u][p] + 1;
                q.push_front({v, p});
            }
        }

        if(dist[u][!p] > dist[u][p] + x) {
            dist[u][!p] = dist[u][p] + x;
            q.push_back({u, !p});
        }
    }

    outln(min(dist[n][0], dist[n][1]));

    return 0;
}
