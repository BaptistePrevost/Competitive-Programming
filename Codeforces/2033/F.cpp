/*
    Problem : https://codeforces.com/contest/2033/problem/F
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


const ull MOD = 1e9 + 7;
const ull N = 1e5+5;

int main() {
    int t;
    cin >> t;

    ull n, k;
    while(t--) {
        cin >> n >> k;
        
        if(k == 1) {
            cout << n % MOD << endl;
            continue;
        }
        ull f0 = 1, f1 = 1, f2;
        ull f = 3;
        vector<ull> z;
        while(true) {
            f2 = (f0+f1) % k;
            f0 = f1;
            f1 = f2;
            if(f0 % k == 1 && f1 % k == 1) break;
            if(f1 % k == 0) z.push_back(f);
            f = (f+1) % MOD;
        }

        ull zs = z.size();
        ull period = z.back();
        ull ans = (((((n/zs)%MOD)*period)%MOD) + (n % zs ? z[n % zs - 1] : 0)) % MOD;
        cout << ans << endl;

    }

    return 0;
}
