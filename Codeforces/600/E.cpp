/*
    Problem : https://codeforces.com/contest/600/problem/E
    Author : Baptiste Prévost
    Subjects : DFS

    Idea : Small to large ! DFS is the right approach to go through the rooted tree
    from the bottom to the top. Frequency of colours in a subtree are stored in 
    unordered maps.
    Let's see the worst case complexity. Suppose each vertex has a different color
    To merge a vertex map with one of its children map, iterate over elements of the
    smallest map of size K. The map is of size at least 2*k.
    Every element that has been moved T time will be in a map of size at least 2^T.
    And 2^T <= n => T <= log_2(n).

    This is the idea of the Union by Rank algorithm for Disjoint Set Union.

    (See this comment : https://codeforces.com/blog/entry/10696?#comment-160306)

    Complexity : O(nlog(n))
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)


ll n;
vector<ll> c;
vector<vector<ll>> adj;
vector<ll> ans;
vector<unordered_map<ll,ll>> freqs;
vector<ll> m;

void treeDfs(ll u, ll prev) {
    freqs[u][c[u]] = 1;
    m[u] = 1;
    ans[u] = c[u];
    for(const ll &v: adj[u]) {
        if(v==prev) continue;
        treeDfs(v,u);
        if(freqs[v].size() > freqs[u].size()) {
            swap(freqs[u], freqs[v]);
            m[u] = m[v];
            ans[u] = ans[v];
        }
        for(auto p : freqs[v]) {
            if(freqs[u].find(p.first) == freqs[u].end()) freqs[u][p.first] = p.second;
            else freqs[u][p.first] += p.second;
            
            if(freqs[u][p.first] > m[u]) {
                m[u] = freqs[u][p.first];
                ans[u] = p.first;
            } else if(freqs[u][p.first] == m[u]) ans[u] += p.first;
        }
    }
}

int main() {
    cin >> n;
    c.resize(n+1);
    forn(i,1,n) cin >> c[i];
    adj.resize(n+1);
    ll x, y;
    forn(j,1,n-1) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ans.resize(n+1);
    freqs.resize(n+1);
    m.resize(n+1);
    treeDfs(1,0);
    forn(i,1,n) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}
