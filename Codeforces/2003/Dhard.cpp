/*
    Problem : https://codeforces.com/contest/2003/D2
    Author : Baptiste Prévost
    Subjects : mex, DP, directed graph, order

    Idea : You have to consider each sequence as an arc, from mex(...sequence) to mex(mex(...sequence), ...sequence)
    By iterating over these vertices in decreasing order (very important, wasn't my first thought), you can compute with DP the largest vertex it can reach.
    We store it in reach[u]

    For any value of x :
        - it can reach any vertex in one operation, i.e the largest vertex
        - it can reach reach[x] if x is a vertex
        - if two sequences share the same mex, then any x can reach reach[mex]
        - finally, initial x can be larger than all this

    For any x lower than the largest vertex, you have to enumerate these conditions.
    For the rest, summation formula is enough.

    Complexity : O(sum_i(l_i))

*/

#include <bits/stdc++.h>
#include <set>
#include <unordered_map>

using namespace std;
typedef long long ll;

const ll MAXN = 200009;


int main() {
    ll t;
    cin >> t;
    
    ll n, m, l, a;
    
    vector<vector<ll>> G(MAXN);
    vector<ll> reach(MAXN);

    while(t--) {
        cin >> n >> m;

        set<ll> vertices;
        set<ll> doubles;
        list<pair<ll, ll>> arcs;
        ll minmex = 0;
        ll maxmex = 0;

        for(int i=0; i<n; i++) {
            cin >> l;
            
            set<ll> s;
            for(ll j=0; j<l; j++) {
                cin >> a;
                s.insert(a);
            }
            bool b = false;
            ll mex;
            for(ll j=0; j<=l+1; j++) {
                if(s.find(j) == s.end()) {
                    if(b) {
                        if(vertices.find(mex) != vertices.end()) {
                            doubles.insert(mex);
                        }
                        vertices.insert(mex);
                        arcs.push_back(make_pair(mex, j));
                        maxmex = max(maxmex, j);
                        break;
                    }
                    mex = j;
                    minmex = max(minmex, mex);
                    b = true;
                }
            }
        }

        
        for(ll i=0; i<=maxmex; i++) vector<ll>().swap(G[i]);
        for(auto arc : arcs) G[arc.first].push_back(arc.second);

        ll maxThatAnyCanReach = 0;
        for(ll u=maxmex; u>=0; u--) {
            reach[u] = max(minmex, u);
            for(ll v : G[u]) {
                reach[u] = max(reach[u], reach[v]);
            }
            if(G[u].size() > 1) maxThatAnyCanReach = max(maxThatAnyCanReach, reach[u]);
        }

        ll ans = 0;
        ll i;
        for(i=0; i<=min(maxmex, m); i++) {
            ans += max(maxThatAnyCanReach, reach[i]);
        }
        ans += m*(m+1)/2 - i*(i-1)/2;

        cout << ans << endl;
    }
}