#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)

int main() {
    ll t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        vector<ll> a(n+1);
        ll mn = 1e15, mx=-1;
        forn(i, 1, n) {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        
        ll low = mn, high = mx;
        ll alpha, beta;
        while(low+1 < high) {
            alpha = (low + high) / 2;
            ll tmp = 0;
            bool valid = true;
            rofn(i, n, 1) {
                tmp += a[i];
                if(tmp > (n-i+1)*alpha) {
                    valid = false;
                    break;
                }
            }
            if(valid) high = alpha;
            else low = alpha;
        }
        alpha = high;

        low = mn; high = mx;
        while(low+1 < high) {
            beta = (low + high) / 2;
            ll tmp = 0;
            bool valid = true;
            forn(i, 1, n) {
                tmp += a[i];
                if(tmp < i*beta) {
                    valid = false;
                    break;
                }
            }
            
            if(valid) low = beta;
            else high = beta;
        }
        beta = low;

        cout << alpha - beta << endl;
    }
}
