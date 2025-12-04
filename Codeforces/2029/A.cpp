#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ll l, r, k;
    ll ans;
    while(t--) {
        cin >> l >> r >> k;
        if(l > r/k) ans = 0;
        else {
            ans = (r/k)-l+1;
        }
        
        cout << ans << endl;
    }

    return 0;
}
