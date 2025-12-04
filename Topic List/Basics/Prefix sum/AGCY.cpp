/*
    Problem : https://www.codechef.com/BYTR20B/problems/AGCY
    Author : Baptiste Prévost
    Subjects : prefix sum, range update

    Idea :

    Complexity : 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();

	int t;
	cin >> t;
	while(t--) {
	    int n, q, l, r;
        cin >> n >> q;
	    vector<int> v(n+2);
	    vector<int> w(n+2);
	    for(int i=0; i<q; i++) {
	        cin >> l >> r;
	        v[l] += 1;
	        v[r+1] -= 1;
            w[r+1] += r-l+1;
	    }
	    
	    int increment = 0;
	    int sum = 0;
	    for(int i=1; i<=n; i++) {
	        increment += v[i];
	        sum += increment;
            sum -= w[i];
	        cout << sum << " ";
	    }
	    cout << endl;
	}
}