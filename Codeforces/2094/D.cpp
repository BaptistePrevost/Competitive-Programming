/*
    Problem : https://codeforces.com/contest/2091/problem/D
    Author : Baptiste Prévost
    Subjects : number theory, arithmetic

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
    int t; in(t)

    while(t--) {
        string p, s; in(p) in(s)
        vll seq1, seq2;

        ll i=1;
        ll prev=0;
        while(i < p.size()) {
            if(p[i] != p[prev]) {
                seq1.push_back(i-prev);
                prev = i;
            }
            i++;
        }
        seq1.push_back(i-prev);

        ll j=1;
        ll qrev=0;
        while(j < s.size()) {
            if(s[j] != s[qrev]) {
                seq2.push_back(j-qrev);
                qrev = j;
            }
            j++;
        }
        seq2.push_back(j-qrev);
        
        bool ans = true;
        if(s[0] != p[0] || seq1.size() != seq2.size()) {
            ans = false;
        } else {
            forn(k,0,seq1.size()-1) {
                ans &= seq1[k] <= seq2[k];
                ans &= seq2[k] <= 2*seq1[k];
            }
        }
        yon(ans)
    }
    

    return 0;
}
