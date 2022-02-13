/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n)  for (int i = 0; i < int(n); i++)
typedef long long int ll;
const ll M=1e9+7;

#define sz(x)       ((ll) (x).size())
#define all(x)      (x).begin(), (x).end()
#define pll         pair<ll,ll>
#define vl          vector<ll>
#define ff          first
#define ss          second
#define pb          push_back
#define pp          pop_back
#define frr(i,j,k)  for(ll i=j; i<k; i++)
#define andar(x)    for(ll&i:x) cin>>i;
#define bahar(x)    for(ll&i:x) cout<<i<<' ';

int n, m, c, u, v;
vector<list< int > > adj(100005, list<int>());
vector<bool> cats(100005, false);
vector<bool> visited(100005, false);

int dfs(int v, int consecutive) {
    if(cats[v]) consecutive++;
    else consecutive=0;
    if(consecutive>m) return 0;
    
    visited[v]=true;
    
    int ans=0;
    bool leaf=true;
    for(int u : adj[v]) {
        if(!visited[u]) {
            leaf=false;
            ans+=dfs(u, consecutive);
        }
    }
    if(leaf) return 1;
    return ans;
}

int main() {

    cin >> n >> m;
    frr(i,1,n+1) {
        cin >> c;
        if(c) cats[i]=true;
    }   
    frr(j,0,n-1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << dfs(1, 0);
    return 0;
}
