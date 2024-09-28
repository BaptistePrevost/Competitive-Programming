#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int MAXN = 200009;

int main() {
    int t;
    cin >> t;
    
    int n;
    vector<int> a(MAXN);
    vector<int> pref(MAXN);
    string s;
    
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        cin >> s;

        pref[0] = a[0];
        for(int i=1; i<n; i++) pref[i] = a[i]+pref[i-1];

        int ans = 0;
        int l=0, r=n-1;
        while(l < r) {
            while(l < r && s[l] != 'L') l++;
            while(r > l && s[r] != 'R') r--;
            
            if(l<r) ans += pref[r] - (l>0 ? pref[l-1] : 0);
            l++;
            r--;
        }

        cout << ans << endl;
    }
}