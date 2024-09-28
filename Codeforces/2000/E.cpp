#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll MAXN = 200009;

int main() {
    ll t;
    cin >> t;
    
    ll n, m, k;
    ll w;
    vector<ll> a(MAXN);
    vector<ll> v(MAXN);
    string s;
    
    while(t--) {
        cin >> n >> m >> k;
        cin >> w;
        for(int i=0; i<w; i++) cin >> a[i];

        for(ll i=0; i<n; i++) {
            for(ll j=0; j<m; j++) {
                v[i*m+j] = min(min(i+1, min(k, n-k+1)), n-i)*min(min(j+1, min(k, m-k+1)), m-j);
            }
        }
        sort(v.begin(), v.begin() + m*n);
        sort(a.begin(), a.begin() + w);
        
        ll ans=0;
        for(int i=0; i<w; i++) {
            ans += v[n*m-i-1]*a[w-i-1];
        }

        cout << ans << endl;
    }
}