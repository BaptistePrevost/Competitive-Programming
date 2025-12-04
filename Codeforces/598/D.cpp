/*
    Problem : https://codeforces.com/contest/598/problem/D
    Author : Baptiste Prévost
    Subjects : DFS

    Idea : Identify rooms by any graph search method, and count walls.

    Complexity : O(n*m)
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

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    forn(i,0,n-1) cin >> s[i];

    vector<ll> ans(n*m, 0);
    vector<ll> parent(n*m, -1);
    forn(i, 0, n-1) {
        forn(j, 0, m-1) {
            ll pos = i*m+j;
            if(s[i][j] == '*') continue;
            if(parent[pos] != -1) continue;
            vector<ll> q = {pos};
            parent[pos] = pos;
            while(!q.empty()) {
                ll cur = q.back();
                q.pop_back();
                if(cur-m >= 0 && parent[cur-m] == -1) {
                    if(s[cur/m - 1][cur%m] == '.') {
                        q.push_back(cur-m);
                        parent[cur-m] = pos;
                    } else ans[pos]++;
                }
                if(cur+m < n*m && parent[cur+m] == -1) {
                    if(s[cur/m + 1][cur%m] == '.') {
                        q.push_back(cur+m);
                        parent[cur+m] = pos;
                    } else ans[pos]++;
                }
                if(cur%m > 0 && parent[cur-1] == -1) {
                    if(s[cur/m][cur%m - 1] == '.') {
                        q.push_back(cur-1);
                        parent[cur-1] = pos;
                    } else ans[pos]++;
                }
                if(cur%m < m-1 && parent[cur+1] == -1) {
                    if(s[cur/m][cur%m + 1] == '.') {
                        q.push_back(cur+1);
                        parent[cur+1] = pos;
                    } else ans[pos]++;
                }
            }
        }
    }

    forn(i,1,k) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        cout << ans[parent[x*m+y]] << endl;
    
        
    }

    return 0;
}
