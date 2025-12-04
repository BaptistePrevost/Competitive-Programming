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

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct DSU {
        vector<int> parent;
        vector<int> size;

        void init(int n) {
            parent.resize(n);
            size.resize(n);
            for(int i=0; i<n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        //With path compression optimisation
        int find(int a) {
            if(a == parent[a]) return a;
            return parent[a] = find(parent[a]);
        }

        //With size balance optimisation
        void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if(a != b) {
                if(size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
            }
        }

};

template<typename T>
struct MergeSort {
    vector<T> arr, L, R;
    MergeSort(size_t n) : arr(n), L(n), R(n) {}

    // Merges ranges [left, mid] and [mid+1, right] in the array
    void merge(int left, int mid, int right) {
        int n = mid-left+1, m = right-mid;
        
        forn(i, 0, n-1) L[i] = arr[left+i];
        forn(j, 0, m-1) R[j] = arr[mid+1+j];

        int i=0, j=0, k=left;
        while(i<n && j<m) {
            if(L[i] < R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while(i<n) {
            arr[k] = L[i];
            i++; k++;
        }
        while(j<m) {
            arr[k] = R[j];
            j++; k++;
        }
    }

    // Recursively partition, then merge segments
    void sort(int left, int right) {
        if(left >= right) return;

        int mid = (left+right)/2;
        sort(left, mid);
        sort(mid+1, right);
        merge(left, mid, right);
    }
};

void treeDfs(const vector<vector<ll>> &adj, ll u, ll prev) {
    for(const ll &v: adj[u]) {
        if(v==prev) continue;
        treeDfs(adj, v, u);
    }
}

struct Combinatorial {
    vector<ll> fact, ifact, twoPows;
    ll n = 2*1e5+5;
    ll MOD = 998244353;

    ll binaryExponentiation(ll base, ll exp) {
        ll ans = 1;
        while(exp > 0) {
            if(exp & 1) {
                ans = (ans*base) % MOD;
            }
            base = (base*base) % MOD;
            exp >>= 1;
        }
        return ans;
    }

    ll among(ll k, ll n) {
        if(k<0 || k>n) return 0;
        return (fact[n]*((ifact[k]*ifact[n-k])%MOD))%MOD;
    }
    
    ll twoPow(ll exp) {
        return twoPows[exp];
    }

    Combinatorial(ll n, ll MOD) : n(n), MOD(MOD) {
        fact.resize(n+1);
        ifact.resize(n+1);
        twoPows.resize(n+1);

        fact[0] = 1;
        forn(i,1,n) fact[i] = (fact[i-1]*i)%MOD;
        ifact[n] = binaryExponentiation(fact[n], MOD-2);
        rofn(i,n-1,0) ifact[i] = (ifact[i+1]*(i+1))%MOD;
        twoPows[0] = 1;
        forn(i,1,n) twoPows[i] = (twoPows[i-1]*2)%MOD;
    }

};

struct SegmentTree {
    // Using https://csacademy.com/lesson/segment_trees
    // Father of segment i is at location floor( (i-1)/2 )
    // Sons are at location 2*i+1 and 2*i+2

    const static ll defaultValue = 0;
    struct Node {
        ll value = defaultValue;
        ll lazy = defaultValue;
    };
    vector<Node> tree;
    int n;

    // Input vector v is labeled from 1 to n
    SegmentTree(const vector<ll> &v, int n) : n(n) {
        tree.resize(2*n+1);
        build(v, 0, 1, n);
    }

    // combination operation used in the query
    ll combine(ll leftValue, ll rightValue) { return leftValue + rightValue; }
    ll resolveLazy(int node, int left, int right) { return (right-left+1) * tree[node].lazy; }

    void update(int pos, ll value) { update(0, 1, n, pos, pos, value); }
    void update(int start, int end, ll value) { update(0, 1, n, start, end, value); }
    ll query(int start, int end) { return query(0, 1, n, start, end); }

    void build(const vector<ll> &v, int node, int left, int right) {
        if(left==right) tree[node].value = v[left];
        else {
            int middle = (left+right)/2;
            build(v, 2*node+1, left, middle);
            build(v, 2*node+2, middle+1, right);
            tree[node].value = combine(tree[2*node+1].value, tree[2*node+2].value);
        }
    }

    void propagate(int node, int left, int right) {
        tree[node].value = resolveLazy(node, left, right);
        if(left < right) {
            tree[2*node+1].lazy = combine(tree[2*node+1].lazy, tree[node].lazy);
            tree[2*node+2].lazy = combine(tree[2*node+2].lazy, tree[node].lazy);
        }
        tree[node].lazy = defaultValue;
    }

    void update(int node, int left, int right, int start, int end, ll value) {
        propagate(node, left, right);
        if(left <= start && right >= end) {
            tree[node].lazy = combine(tree[node].lazy, value);
            return;
        }
        int middle = (left+right)/2;
        if(start <= middle) update(2*node+1, left, middle, start, end, value);
        if(end >= middle+1) update(2*node+2, middle+1, right, start, end, value);

        propagate(2*node+1, left, middle);
        propagate(2*node+2, middle+1, right);
        tree[node].value = combine(tree[2*node+1].value, tree[2*node+2].value);
    }
    
    ll query(int node, int left, int right, int start, int end) {
        propagate(node, left, right);
        if(start <= left && end >= right) return tree[node].value;

        ll ans = defaultValue;
        int middle = (left+right)/2;
        if(start <= middle) ans = combine(ans, query(2*node+1, left, middle, start, end));
        if(end >= middle+1) ans = combine(ans, query(2*node+2, middle+1, right, start, end));
        return ans;
    }
};

int main() {
    fastIO();
    int t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        
        
        cout << endl;
    }

    return 0;
}
