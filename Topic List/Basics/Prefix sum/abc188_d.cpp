/*
    Problem : https://atcoder.jp/contests/abc188/tasks/abc188_d
    Author : Baptiste Prévost
    Subjects : prefix sum, range update, sort, coordinate compression

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

	ll n, q;
	cin >> n >> q;
	ll a, b, c;
	map<ll, ll> m;
	forn(i,1,n) {
		cin >> a >> b >> c;
		if(m.find(a) == m.end()) m[a] = 0;
		if(m.find(b+1) == m.end()) m[b+1] = 0;
		m[a] += c;
		m[b+1] -= c;
	}

	ll pref = 0;
	ll ans = 0;
	ll last = 0;
	for(auto &kv : m) {
		ans += (kv.first-last)*min(pref, q);
		last = kv.first;
		pref += kv.second;
	}

	cout << ans << endl;


	return 0;
}