/*
    Problem : https://codeforces.com/contest/1592/problem/C
    Author : Baptiste Prévost
    Subjects : XOR, DFS, tree

    Idea : Let's consider x = XOR(a). Either x = 0, and disconnecting any edge will solve the problem, or x > 0.
    Then consider a solution with q trees. Merging three of them into one (q := q-2) results in another solution 
    with q-2 trees, because ((x XOR x) XOR x) = x
    If such a solution exists, we only need to remove 2 edges. The first to create a tree of XOR x, and another 
    of XOR 0. It will be larger than 1 vertex since a_i > 0, and we are back to case where XOR = 0.
    
    We first root the tree, and then DFS to find a subtree of XOR 0 (or x).

    Complexity : n
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)

vector<vector<ll>> adj;
vector<ll> a;
ll x;
ll foundU;
ll foundPrev;
bool success;
 
ll treeDfs(ll root, ll u, ll prev) {
    ll y = a[u];
    for(const ll &v: adj[u]) {
        if(v==prev) continue;
        y ^= treeDfs(root, v, u);
    }
 
    if(!success && u != root && y == x) {
        foundU = u;
        foundPrev = prev;
        success = true;
    }
    return y;
}

int main() {
    int t;
    cin >> t;

    ll n, k, u, v;
    while(t--) {
        cin >> n >> k;
        adj = vector<vector<ll>>(n+1);
        a = vector<ll>(n+1);
        x = 0;
        forn(i, 1, n) {
            cin >> a[i];
            x ^= a[i];
        }
        forn(i, 1, n-1) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(x==0) {
            cout << "YES";
        } else if (k <= 2) {
            cout << "NO";
        } else {    
            success = false;
            treeDfs(1, 1, 0);
            if(success) {
                // Subtree of foundU of tree rooted in 1 has XOR = x
                success = false;
                treeDfs(foundU, foundPrev, foundU);
                if(success) cout << "YES";
                else cout << "NO";
            } else cout << "NO";
        }
        
        cout << endl;
    }

    return 0;
}
