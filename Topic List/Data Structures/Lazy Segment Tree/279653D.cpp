/*
    Problem : https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/D
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



ll combine(ll lv, ll rv) { return lv+rv; }
ll defaultValue() { return 0; }

int main() {
    fastIO();
    
    ll n, m;
    in(n) in(m)
    vll v(n+1);
    LazySegmentTree<ll, combine, defaultValue> lst(v);

    ll a, b, c, d;
    forn(i,1,m) {
        in(a) in(b) in(c)
        if(a == 1) {
            in(d)
            lst.update(b+1, c, d, 0, 1, n);
        } else {
            outln(lst.query(b+1, c))
        }
    }

    return 0;
}
