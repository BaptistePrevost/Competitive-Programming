/*
    Problem : https://atcoder.jp/contests/abc179/tasks/abc179_d
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

	const ll MOD = 998244353;

	ll n, k;
	cin >> n >> k;
	ll l[k+1], r[k+1];
	forn(i,1,k) {
		cin >> l[i] >> r[i];
	}
	vector<ll> dp(n+1);
	vector<ll> v(n+2);
	v[1] = 1; v[2] = -1;
	ll pref = 0;
	forn(i,1,n) {
		pref = (pref + v[i]) % MOD;
		dp[i] = pref;
		forn(j,1,k) {
			if(i+l[j]<=n) {
				v[i+l[j]] = (v[i+l[j]] + pref) % MOD;
				v[min(i+r[j]+1, n+1)] = (v[min(i+r[j]+1, n+1)]+MOD-pref)%MOD;
			}
		}
	}
	cout << pref << endl;
	return 0;
}