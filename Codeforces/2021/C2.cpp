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
    int t;
    cin >> t;

    ll n, m, q;
    ll s, u;
    while(t--) {
        cin >> n >> m >> q;
        vector<ll> a(n+1), b(m+1);
        forn(i,1,n) cin >> a[i];
        forn(j,1,m) cin >> b[j];

        vector<set<ll>> pos(n+1);
        vector<ll> ra(n+1);
        forn(i,1,n) ra[a[i]] = i;
        vector<ll> first(n+1, m+1);
        ll nbConflicts = 0;
        forn(j,1,m) {
            first[b[j]] = min(first[b[j]], j);
            pos[b[j]].insert(j);
        }
        bool ans = first[a[1]] == 1;
        forn(i,1,n-1) {
            if(first[a[i]] > first[a[i+1]]) {
                ans = false;
                nbConflicts++;
            }
        }

        cout << (ans ? "YA" : "TIDAK") << endl;

        forn(k,1,q) {
            cin >> s >> u;

            // Remove local conflicts
            if(ra[u] > 1 && first[a[ra[u]-1]] > first[u]) nbConflicts--;
            if(ra[u] < n && first[u] > first[a[ra[u]+1]]) nbConflicts--;

            if(ra[b[s]] > 1 && first[a[ra[b[s]]-1]] > first[b[s]] && a[ra[b[s]]-1] != u) nbConflicts--;
            if(ra[b[s]] < n && first[b[s]] > first[a[ra[b[s]]+1]] && a[ra[b[s]]+1] != u) nbConflicts--;

            // Update pos and first vectors
            pos[b[s]].erase(s);
            if(pos[b[s]].size() > 0) first[b[s]] = *pos[b[s]].begin();
            else first[b[s]] = m+1;
            pos[u].insert(s);
            first[u] = min(first[u], s);

            // Count local conflicts
            if(ra[u] > 1 && first[a[ra[u]-1]] > first[u]) nbConflicts++;
            if(ra[u] < n && first[u] > first[a[ra[u]+1]]) nbConflicts++;
            
            if(ra[b[s]] > 1 && first[a[ra[b[s]]-1]] > first[b[s]] && a[ra[b[s]]-1] != u) nbConflicts++;
            if(ra[b[s]] < n && first[b[s]] > first[a[ra[b[s]]+1]] && a[ra[b[s]]+1] != u) nbConflicts++;
            
            // Update b
            b[s] = u;

            ans = (first[a[1]] == 1) && (nbConflicts == 0);
            cout << (ans ? "YA" : "TIDAK") << endl;
        }
    }

    return 0;
}
