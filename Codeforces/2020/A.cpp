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
#define forv(b,a) for(auto &b : a)
#define debug(x) cout << x << endl;

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
    int t;
    cin >> t;

    ull n, k;
    while(t--) {
        cin >> n >> k;
        ull ans = 0;
        if(k > n || k == 1) {
            ans = n;
        } else {
            while(n > 0) {
                if(k > n) {
                    ans += n;
                    break;
                }
                ull l = k;
                while(l*l <= n) l *= l;
                while(l*k <= n) l *= k; 
                n -= l;
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
