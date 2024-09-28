/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>

#include <algorithm>

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
    int n, q;
    cin >> n >> q;

    struct P {
        char c;
        bool operator<(const P &p) {
            cout << "? " << c << " " << p.c << endl;
            char b;
            cin >> b;
            if(b == '<') return true;
            return false;
        }
    };

    MergeSort<P> m(n);
    forn(i, 0, n-1) m.arr[i] = {(char)('A'+i)};

    cout << "! ";
    forn(i, 0, n-1) cout << m.arr[i].c;
    cout << endl;

    return 0;
}
