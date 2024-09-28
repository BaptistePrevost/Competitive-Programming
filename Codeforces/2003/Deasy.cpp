#include <bits/stdc++.h>
#include <set>

using namespace std;
typedef long long ll;

const ll MAXN = 200009;

int main() {
    ll t;
    cin >> t;
    
    ll n, m, l, a;

    while(t--) {
        cin >> n >> m;

        ll maxmex =  0;
        for(int i=0; i<n; i++) {
            cin >> l;
            
            set<ll> s;
            for(ll j=0; j<l; j++) {
                cin >> a;
                s.insert(a);
            }
            bool b = false;
            for(ll j=0; j<=l+1; j++) {
                if(s.find(j) == s.end()) {
                    maxmex = max(maxmex, j);
                    if(b) break;
                    b = true;
                }
            }
        }
        
        ll ans;
        if(maxmex >= m) {
            ans = (m+1)*maxmex;
        } else {
            ans = (maxmex+1)*maxmex + m*(m+1)/2 - maxmex*(maxmex+1)/2;
        }

        cout << ans << endl;
    }
}