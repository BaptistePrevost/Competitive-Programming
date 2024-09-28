/*
    Problem : https://codeforces.com/contest/2005/B
    Author : Baptiste Prévost
    Subjects : binary search

    Idea : Use binary search to find the closest teachers. O(1) then.

    Complexity : qlogm
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll MAXN = 200009;

int main() {
    ll t;
    cin >> t;

    ll n, m, q;
    vector<ll> b(MAXN);
    ll a;
    while(t--) {
        cin >> n >> m >> q;
        for(ll i=0; i<m; i++) cin >> b[i];
        sort(b.begin(), b.begin() + m);

        ll ans;
        for(int i=0; i<q; i++) {
            cin >> a;
            if(a < b[0]) {
                ans = b[0]-1;
            } else if(a > b[m-1]) {
                ans = n-b[m-1];
            } else {

                int l=-1, r=m;
                while(b[l] > a || b[l+1] < a) {
                    int j = (l+r)/2;
                    if(b[j] > a) r = j+1;
                    else l = j;
                }
                ans = (b[l+1] - b[l])/2;
            }
            cout << ans << endl;
        }
    }
}
