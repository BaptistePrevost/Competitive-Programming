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

template<
    typename T,
    T (*combine)(T, T),
    T (*defaultValue)()
>
struct SegmentTree {
    public:
        SegmentTree(int n) : SegmentTree(vector<T>(n, defaultValue())) {}
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


/**
 * WIP : The policy used in push is specific to the sum operator
 */
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
            data.resize(2*_size, {defaultValue(), defaultValue()});
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
            push(node, left, right);
            if(right < start || end < left) return defaultValue();
            if(start <= left && right <= end) return data[node].value;
            int mid = (left+right) / 2;
            return combine(query(2*node+1, start, end, left, mid), query(2*node+2, start, end, mid+1, right));
        }

        void push(int node, int left, int right) {
            if(data[node].lazy == defaultValue()) return;
            data[node].value = combine(data[node].value, (right-left+1)*data[node].lazy); //TODO
            if(left != right) {
                data[2*node+1].lazy = combine(data[2*node+1].lazy, data[node].lazy);
                data[2*node+2].lazy = combine(data[2*node+2].lazy, data[node].lazy);
            }
            data[node].lazy = defaultValue();
        }

        void pull(int node) {
            data[node].value = combine(data[2*node+1].value, data[2*node+2].value);
        }

        void update(int start, int end, T val, int node, int left, int right) {
            push(node, left, right);
            if(right < start || end < left) return;
            if(start <= left && right <= end) {
                data[node].lazy = val;
                push(node, left, right);
                return;
            }
            int mid = (left+right) / 2;
            update(start, end, val, 2*node+1, left, mid);
            update(start, end, val, 2*node+2, mid+1, right);
            pull(node);
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
                pull(node);
            }
        }
};