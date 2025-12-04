/*
    Problem : https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

template<typename T, T (*combine)(T, T), T (*defaultValue)()>
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
            return data[_size+pos];
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

struct Node {
    ll val;
    ll count;
};
Node combine(Node lv, Node rv) { 
    if(lv.val == rv.val) return {lv.val, lv.count + rv.count};
    if(lv.val < rv.val) return lv;
    return rv;
}
Node defaultValue() { return {1000000009, 1}; }

int main() {
    fastIO();
    ll n, m;
    cin >> n >> m;
    vector<Node> v(n+1);
    ll val;
    forn(i,1,n) {
        cin >> val;
        v[i] = {val , 1};
    }
    SegmentTree<Node, combine, defaultValue> seg(v);

    int a, b, c;
    forn(i,1,m) {
        cin >> a >> b >> c;
        if(a==1) {
            b++;
            seg.set(b, {c,1});
        } else {
            b++;
            Node node = seg.query(b, c);
            cout << node.val << " " << node.count << endl;
        }
    }

    return 0;
}
