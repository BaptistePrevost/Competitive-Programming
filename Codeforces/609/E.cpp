/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj(n+1);
    vector<tuple<ll, ll, ll>> edges;
    vector<ll> es;
    ll u, v, w;
    forn(i,0,m-1) {
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u,v,w));
        es.push_back(i);
    }

    sort(es.begin(), es.end(), [&](const ll &i1, const ll &i2){return get<2>(edges[i1]) < get<2>(edges[i2]);});
    
    vector<ll> ans(m+1, 0);
    ll mstW = 0;
    forn(i,0,n-2) mstW += get<2>(edges[es[i]]);
    forn(i,0,n-2) ans[es[i]] = mstW;

    forn(i,n-1,m-1) {

    }

    cout << mstW << endl;
    return 0;
}
