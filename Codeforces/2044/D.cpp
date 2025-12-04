/*
    Problem : https://codeforces.com/contests/2044/problems/D
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

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ll n, m;
    vector<ll> a;
    set<ll> other;
    while(t--) {
        m = 0;
        cin >> n;
        a.resize(n+1);
        forn(i,1,n) other.insert(i);
        forn(i,1,n) {
            cin >> a[i];
            m = max(m, a[i]);
            other.erase(a[i]);
        }

        m++;
        vector<bool> seen(m+1, false);
        forn(i,1,n) {
            if(seen[a[i]]) {
                cout << *other.begin() << ' ';
                other.erase(*other.begin());
            }
            else {
                seen[a[i]] = true;
                cout << a[i] << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}
