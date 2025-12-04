/*
    Problem : 
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
typedef vector<ll> vll;
typedef unordered_set<ll> sll;

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

struct SegTree {
    vll cnt;
    int n;
    SegTree(const vll &v) : n(v.size()-1) { //indexed from 1 to n
        ll size = 1;
        while(size < v.size()-1) size <<= 1;
        cnt.resize(2*size, 0);
        build(v, 0, 1, n);
    }

    sll* build(const vll &v, int node, int left, int right) {
        if(left == right) {
            cnt[node] = 1;
            sll* s = new sll();
            s->insert(v[left]);
            return s;
        } else {
            int mid = (left+right) / 2;
            sll* s1 = build(v, 2*node+1, left, mid);
            sll* s2 = build(v, 2*node+2, mid+1, right);
            if(s1->size() > s2->size()) swap(s1, s2);
            for(auto it=s1->begin(); it!=s1->end(); it++) {
                s2->insert(*it);
            }
            cnt[node] = s2->size();
            return s2;
        }
    }

    ll query(int start, int end) {
        assert(1 <= start && start <= end && end <= n);
        return query(0, start, end, 1, n);
    }

    ll query(int node, int start, int end, int left, int right) {
        if(start <= left && end >= right) return cnt[node];
        int mid = (left+right) / 2;
        ll ans = 0;
        if(start <= mid) ans += query(2*node+1, start, end, left, mid);
        if(end >= mid+1) ans += query(2*node+2, start, end, mid+1, right);
        return ans;
    }
};


int main() {
    fastIO();
    ll n; in(n)
    vll a(n+1);
    forn(i,1,n) in(a[i]);

    SegTree st(a);

    // vll l(n+1), r(n+1);

    // unordered_set<ll> s;
    // forn(i,1,n) {
    //     s.insert(a[i]);
    //     l[i] = s.size();
    // }
    // s.clear();
    // rofn(i,n,1) {
    //     s.insert(a[i]);
    //     r[i] = s.size();
    // }

    // ll ans = 0;
    // forn(i,1,n-1)
    //     ans = max(ans, l[i] + r[i+1]);
    // outln(ans)
    forn(i,1,n) {
        forn(j,i,n) {
            out(i) out(j) outln(st.query(i,j));
        }
    }

    return 0;
}
