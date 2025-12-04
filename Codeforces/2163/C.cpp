/*
    Problem : https://codeforces.com/contest/2163/problem/B
    Author : Baptiste Prévost
    Subjects : 

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef long long ll;
typedef unsigned long long ull;
typedef unordered_map<long long, long long, custom_hash> safeMap;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pll> vpll;


#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "Yes" : "No") << endl;
#define in(n) cin >> n;
#define inll(n) ll n; in(n);
#define inv(a,n) vll a(n+1); forn(i,1,n) in(a[i]);
#define inc(c) char c; in(c);
#define ins(s) string s; in(s);
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t; in(t)
    
    while(t--) {
        inll(n)
        inv(a,n);
        inv(b,n);
        vll minpa(n+1,2*n+1);
        vll maxpa(n+1,0);
        forn(i,1,n) minpa[i] = min(minpa[i-1],a[i]); 
        forn(i,1,n) maxpa[i] = max(maxpa[i-1],a[i]); 
        vll minsb(n+2,2*n+1);
        vll maxsb(n+2,0);
        rofn(i,n,1) minsb[i] = min(minsb[i+1],b[i]); 
        rofn(i,n,1) maxsb[i] = max(maxsb[i+1],b[i]);

        ll ans=0;
        forn(l,1,2*n) {
            // right-most index j st a[1], ..., a[j] >= l
            ll left=0, right=n+1;
            while(right-left>1) {
                ll mid = (left+right)/2;
                if (minpa[mid]>=l) left=mid;
                else right=mid;
            }
            ll leftItvEnd = left;

            
            // left-most index k st b[k], ..., b[n] >= l
            left=0, right=n+1;
            while(right-left>1) {
                ll mid = (left+right)/2;
                if (minsb[mid]>=l) right=mid;
                else left=mid;
            }
            ll leftItvStart = right;

            if (leftItvStart > leftItvEnd) continue;
            
            // minimum r st there is a path
            left=l-1, right=2*n+1;
            while(right-left>1) {
                ll mid = (left+right)/2;
                
                // right-most index j st a[1], ..., a[j] <= mid (=r)
                ll left2=0, right2=n+1;
                while(right2-left2>1) {
                    ll mid2 = (left2+right2)/2;
                    if (maxpa[mid2]<=mid) left2=mid2;
                    else right2=mid2;
                }
                ll rightItvEnd = left2;

                
                // left2-most index k st b[k], ..., b[n] <= mid (=r)
                left2=0, right2=n+1;
                while(right2-left2>1) {
                    ll mid2 = (left2+right2)/2;
                    if (maxsb[mid2]<=mid) right2=mid2;
                    else left2=mid2;
                }
                ll rightItvStart = right2;

                if (max(leftItvStart, rightItvStart) > min(leftItvEnd, rightItvEnd)) left=mid;
                else right=mid;
            }

            ans += 2*n-left;
        }
        outln(ans)
    }

    return 0;
}