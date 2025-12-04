/*
    Problem : https://atcoder.jp/contests/abc389/tasks/abc389_f
    Author : Baptiste Prévost
    Subjects : lazy segment tree

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

template<
    typename T,
    T (*combine)(T, T),
    T (*defaultValue)()
>
struct LazySegmentTree {

    struct Node {
        T lazy = defaultValue();
        T value = defaultValue();
    };

    public:
        LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, defaultValue())) {}
        LazySegmentTree(const vector<T> &v) : _n(v.size()-1) {
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
            propagate(node);
            if(start <= left && end >= right) return data[node].value;
            int mid = (left+right) / 2;
            T ans = defaultValue();
            if(start <= mid) ans = combine(ans, query(2*node+1, start, end, left, mid));
            if(end >= mid+1) ans = combine(ans, query(2*node+2, start, end, mid+1, right));
            return ans;
        }

        void propagate(int node) {
            data[node].value = combine(data[node].value, data[node].lazy);
            if(2*node+1 < _size) data[2*node+1].lazy = combine(data[2*node+1].lazy, data[node].lazy);
            if(2*node+2 < _size) data[2*node+2].lazy = combine(data[2*node+2].lazy, data[node].lazy);
            data[node].lazy = defaultValue();
        }

        void update(int start, int end, T val, int node, int left, int right) {
            propagate(node);
            if(start <= left && right <= end) {
                data[node].lazy = val;
                return;
            }
            int mid = (left+right) / 2;
            if(start <= left <= mid) update(start, end, val, 2*node+1, left, mid);
            if(mid+1 <= right <= end) update(start, end, val, 2*node+2, mid+1, right);
            data[node].value = combine(data[2*node+1].value, data[2*node+2].value);
        }

    private:
        vector<Node> data;
        int _n, _size;
        void build(const vector<T> &v, int node, int left, int right) {
            if(left == right) {
                data[node] = {defaultValue(), v[left]};
            } else {
                int mid = (left+right) / 2;
                build(v, 2*node+1, left, mid);
                build(v, 2*node+2, mid+1, right);
                data[node] = {defaultValue(), combine(data[2*node+1], data[2*node+2])};
            }
        }
};



ll combine(ll lv, ll rv) { return lv+rv; }
ll defaultValue() { return 0; }

int main() {
    fastIO();

    const int maxX = 500009;
    vector<int> ratings(maxX);
    forn(i,1,maxX) ratings[i] = i;
    LazySegmentTree<ll, combine, defaultValue> lst(ratings, maxX);

    int n;
    cin >> n;
    int l, r;
    forn(i,1,n) {
        cin >> l >> r;
        seg.update(l, r, 1);
    }

    int q, x;
    cin >> q;
    forn(i,1,q) {
        cin >> x;
        cout << seg.query(x,x) << endl;
    }
    return 0;
}
