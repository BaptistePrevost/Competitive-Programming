/*
    Problem : https://codeforces.com/contests/2044/problems/E
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

#define forn(i,j,k) for(ull i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ull i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ull lower(ull l, ull r, ull k, vector<ll> &a) {
    // Returns the first index in a st a[index] > k
    while(r-l>1) {
        ull m = (l+r)>>1;
        if(a[m] <= k) l = m;
        else r = m;
    }
    return l+1;
}

ull upper(ull l, ull r, ull k, vector<ll> &a) {
    // Returns the last index in a st a[index] < k
    while(r-l>1) {
        ull m = (l+r)>>1;
        if(a[m] >= k) r = m;
        else l = m;
    }
    return r-1;
}

ull fastPow(ull a, ull b) {
    ull res=1;
    while(b) {
        if(b&1) res*=a;
        a=a*a;
        b>>=1;
    }
    return res;
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ull k, l1, r1, l2, r2;
    while(t--) {
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ull ans=0;
        ull kn=1; // k^0 = 1

        while (kn <= r2) {
            ull minX = max(l1, (l2 + kn - 1) / kn);
            ull maxX = min(r1, r2 / kn);
            
            if (minX <= maxX) {
                ans += (maxX - minX + 1);
            }
            
            if (kn > r2 / k) break;
            kn *= k;
        }

        cout << ans << endl;
    }

    return 0;
}
