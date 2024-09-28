#include <bits/stdc++.h>
#include <vector>

typedef long long ll;
using namespace std;

const ll MAXN = 200009;

int main() {
    ll t;
    cin >> t;
    ll n;
    vector<ll> a(MAXN);
    
    while(t--) {
        cin >> n;
        for(ll i=0; i<n; i++) cin >> a[i];

        sort(a.begin(), a.begin() + n);


        cout << a[n/2] << endl;
    }
}