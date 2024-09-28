#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, l, r;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        int ans=1;
        int val=l;
        while(val<=r) {
            val += ans++;
        }
        cout << ans-1 << endl;
    }
}