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

    ll n;
    string s, r;
    bool ans;
    while(t--) {
        cin >> n >> s >> r;
        int n0 = 0;
        int n1 = 0;
        forn(i,0,n-1) {
            if(s[i] == '0') n0++;
            else n1++;
        }
        ans = true;
        forn(i,0,n-2) {
            if(n0*n1==0) {
                ans = false;
                break;
            }
            if(r[i] == '0') n1--;
            else n0--;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
