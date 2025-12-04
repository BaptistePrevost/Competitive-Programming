/*
    Problem : https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D
    Author : Baptiste Prévost
    Subjects : segment tree

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;
#define in(x) cin >> x;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

template<typename T, T (*combine)(T, T), T (*defaultValue)()>
struct SegmentTree {
    public:
        SegmentTree(int n) : SegmentTree(vector<T>(n+1, defaultValue())) {}
        SegmentTree(const vector<T> &v) : _n(v.size()-1) {
            _size = 1;
            while(_size < _n) _size <<= 1;
            data.resize(2*_size, defaultValue());
            build(v, 0, 1, _n);
        }

        T get(int pos) {
            assert(pos >= 1 && pos <= _n);
            return query(pos, pos);
        }

        T query(int start, int end) {
            assert(1 <= start && start <= end && end <= _n);
            return query(0, start, end, 1, _n);
        }

        T query(int node, int start, int end, int left, int right) {
            if(start <= left && end >= right) return data[node];
            int mid = (left+right) / 2;
            T ans = defaultValue();
            if(start <= mid) ans = combine(ans, query(2*node+1, start, end, left, mid));
            if(end >= mid+1) ans = combine(ans, query(2*node+2, start, end, mid+1, right));
            return ans;
        }

        void set(int pos, T val) {
            assert(pos >= 1 && pos <= _n);
            set(pos, val, 0, 1, _n);
        }

        void set(int pos, T val, int node, int left, int right) {
            if(left == right) {
                data[node] = val;
                return;
            }
            int mid = (left+right) / 2;
            if(pos <= mid) set(pos, val, 2*node+1, left, mid);
            else set(pos, val, 2*node+2, mid+1, right);
            data[node] = combine(data[2*node+1], data[2*node+2]);
        }

        T find(ll k, ll j, int node, int left, int right) {
            if(data[node] < k || right < j) return _n+1;
            if(left == right) return left;
            int mid = (left+right) / 2;
            ll ret = find(k, j, 2*node+1, left, mid);
            if(ret<_n) return ret;
            return find(k, j, 2*node+2, mid+1, right);
        }

    private:
        vector<T> data;
        int _n, _size;
        void build(const vector<T> &v, int node, int left, int right) {
            if(left == right) {
                data[node] = v[left];
            } else {
                int mid = (left+right) / 2;
                build(v, 2*node+1, left, mid);
                build(v, 2*node+2, mid+1, right);
                data[node] = combine(data[2*node+1], data[2*node+2]);
            }
        }
};


ll combine(ll lv, ll rv) { return max(lv, rv); }
ll defaultValue() { return LLONG_MAX; }

int main() {
    fastIO();
    ll n, m;
    in(n) in(m)
    vector<ll> v(n+1);
    forn(i,1,n) {in(v[i])}
    SegmentTree<ll, combine, defaultValue> seg(v);
    
    ll x, y, z;
    forn(i,1,m) {
        in(x) in(y) in(z)
        if(x==1) {
            seg.set(y+1, z);
        } else {
            ll ans = seg.find(y, z+1, 0, 1, n);
            outln((ans <= n ? ans-1 : -1))
        }
    }

    return 0;
}
