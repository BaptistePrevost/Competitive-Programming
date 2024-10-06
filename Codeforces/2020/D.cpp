/*
    Problem : https://codeforces.com/contest/2020/problem/D
    Author : Baptiste Prévost
    Subjects : connected components, ranges, dp

    Idea :

    Complexity : O(n*d + m)
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define dbg(n) cout << n << endl;


struct DSU {
        vector<ll> parent;
        vector<ll> size;

        void init(ll n) {
            parent.resize(n);
            size.resize(n);
            for(ll i=0; i<n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        //With path compression optimisation
        ll find(ll a) {
            if(a == parent[a]) return a;
            return parent[a] = find(parent[a]);
        }

        //With size balance optimisation
        void merge(ll a, ll b) {
            a = find(a);
            b = find(b);
            if(a != b) {
                if(size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
};

int main() {
    ll t;
    cin >> t;

    ll n, m;
    ll a, d, k;
    while(t--) {
        cin >> n >> m;

        vector<vector<pair<ll, ll>>> queries(n+1);
        forn(i,1,m) {
            cin >> a >> d >> k;
            queries[a].push_back({d,k});
        }

        DSU dsu;
        dsu.init(n+1);

        // Stored by step d and by rest in the division by d
        vector<vector<ll>> latestEnd(11, vector<ll>(11, -1));
        forn(a,1,n) {
            for(pair<ll, ll> q : queries[a]) {
                d = q.first; k = q.second;
                latestEnd[d][a%d] = max(latestEnd[d][a%d], a+k*d);
            }
            forn(d,1,10) {
                if(latestEnd[d][a%d] > a) {
                    // Query is active
                    dsu.merge(a, a+d);
                }
            }
        }

        vector<bool> visited(n+1, false);
        ll ans = 0;
        forn(i,1,n) {
            ll rep = dsu.find(i);
            if(visited[rep]) continue;
            visited[rep] = true;
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}