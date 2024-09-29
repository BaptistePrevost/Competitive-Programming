/*
    Problem : 
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

int main() {
    ll n, m;
    ll u, v, w;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1);
    vector<vector<pair<ll, ll>>> invAdj(n+1);
    forn(j, 1, m) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        invAdj[v].push_back({u, w});
    }

    vector<bool> visited(n+1, false);
    vector<ll> ans(n+1, 200401298);
    forn(i, 1, n) {
        vector<ll> s = {i};
        while(!s.empty()) {
            u = s.back();
            s.pop_back();
            for(const pair<ll, ll> &p : adj[u]) {
                v = p.first;
                w = p.second;
                if(!visited[v]) {
                    s.push_back(v);
                    ans[v] = ans[u] + w;
                    visited[v] = true;
                }
            }
            for(const pair<ll, ll> &p : invAdj[u]) {
                v = p.first;
                w = p.second;
                if(!visited[v]) {
                    s.push_back(v);
                    ans[v] = ans[u] - w;
                    visited[v] = true;
                }
            }
        }
    }

    forn(i, 1, n) cout << ans[i] << " ";
    cout << endl;
}
