/*
    Problem : https://codeforces.com/contest/2091/problem/E
    Author : Baptiste Prévost
    Subjects : dynamic programming, prefix sum

    Idea : The base idea is dynamic programming problem, but with a naive approach, each calculation takes O(d)
    A better approach is to use prefix sum.

    Complexity : O(n*m)
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
typedef vector<ll> vll;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "Yes" : "No") << endl;
#define in(n) cin >> n;
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    const ll MOD = 998244353;
    int t; in(t)

    while(t--) {
        ll q, s, k;
        in(q)
        bool reversed=false;
        ll ans1=0, ans2=0;
        ll sm=0;
        deque<ll> a;
        forn(i,1,q) {
            in(s);
            if(s == 1) {
                if(reversed) {
                    k = a.front();
                    ans1 = ans1-sm+a.size()*k;
                    ans2 = ans2+sm-a.size()*k;
                    a.pop_front();
                    a.push_back(k);
                } else {
                    k = a.back();
                    ans1 = ans1+sm-a.size()*k;
                    ans2 = ans2-sm+a.size()*k;
                    a.pop_back();
                    a.push_front(k);
                }
            } else if(s==2) {
                reversed = !reversed;
            } else {
                in(k)
                sm += k;
                if(reversed) {
                    a.push_front(k);
                    ans1 += sm;
                    ans2 += k*a.size();
                }
                else {
                    a.push_back(k);
                    ans1 += k*a.size();
                    ans2 += sm;
                }
            }

            if(reversed) outln(ans2)
            else outln(ans1)
        }
    }
    

    return 0;
}
