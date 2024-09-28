/*
    Problem : https://codeforces.com/contest/2008/problem/H
    Author : Baptiste Prévost
    Subjects : binary search, number theory

    Idea : Sort the "a" array and precalculate pref[i] the number of elements less than i in "a".
    For each value of q, we will perform a binary search for the median m to display.

    The binary search was hard for me to find. I just wanted to enumerate all possible values in increasing order for the median,
    and update the number of elements with less. This is slower than with binary search. 
    It is always important to take advantage of sorted data. With multiple requests, a logn binary search complexity is better.

    Complexity: Sort is nlogn. Each evaluation in the binary search is n/x, so each query is in (n/x)logn.
    We have q values of x in range [1,n]. The worst case is to have them all.
    sum_x=1^x=n(n/x)=nlog(n).
    Result is nlog^2n
*/

#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 100009;

using namespace std;

int main() {
    int t, n, q, x;
    int index;
    int l,r,m;
    int lessCount, exactCount, target;
    vector<int> a(MAXN);
    vector<int> pref(MAXN);
    vector<int> ans(MAXN);
    cin >> t;

    while(t--) {
        cin >> n >> q;
        
        for(int i=0; i<n; i++) cin >> a[i];

        sort(a.begin(), a.begin()+n);
        pref[0] = 0;
        index = 0;
        for(int i=0; i<n; i++) {
            while(index < a[i]) {
                index++;
                pref[index] = pref[index-1];
            }
            pref[index]++;
        }

        target = (n%2 == 0) ? (n+2)/2 : (n+1)/2;

        for(int x=1; x<=n; x++) {
            l = -1, r = x;
            while (r - l > 1) {
                m = (l + r) / 2;
                exactCount = 0;
                lessCount = 0;
                for(int k=0; k*x<=a[n-1]; k++) {
                    if(k*x+m <= a[n-1]) {
                        lessCount += pref[k*x+m]-(k>0 ? pref[k*x-1] : 0);
                        exactCount += pref[k*x+m] - (k+m>0 ? pref[k*x+m-1] : 0);
                    } else {
                        lessCount += pref[a[n-1]]-(k>0 ? pref[k*x-1] : 0);
                    }
                }
                if(lessCount < target) {
                    l = m;
                } else if(lessCount - exactCount >= target) {
                    r = m;
                } else {
                    ans[x] = m;
                    break;
                }
            }
        }

        for(int i=0; i<q; i++) {
            cin >> x;
            cout << ans[x] << " ";
        }
        cout << endl;
    }

}