/*
    Problem : https://codeforces.com/contest/598/problem/E
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

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

vector<vector<vector<ll>>> mem(31, vector<vector<ll>>(31, vector<ll>(51, 0)));

ll dp(ll n, ll m, ll k) {
    if(n > m) swap(n,m);
    if(mem[n][m][k] || n*m == k || k == 0) return mem[n][m][k];
    ll ret = 1e18;
    forn(i,1,n-i) {
        forn(j,0,k) {
            ret = min(ret, m*m + dp(i, m, j) + dp(n-i, m, k-j));
        }
    }
    forn(i,1,m-i) {
        forn(j,0,k) {
            ret = min(ret, n*n + dp(n, i, j) + dp(n, m-i, k-j));

        }
    }
    return mem[n][m][k] = ret;
}

int main() {
    int t;
    cin >> t;
    forn(i,1,30) {
        forn(j,i,30) {
            if(i*j <= 50) mem[i][j][i*j] = 0;
        }
    }

    ll n, m, k;
    while(t--) {
        cin >> n >> m >> k;
        cout << dp(n, m, k) << endl;
    }

    return 0;
}