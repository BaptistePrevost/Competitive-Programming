#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int MAXN = 200009;

int main() {
    int t;
    cin >> t;
    
    int n, m;
    vector<int> a(MAXN);
    string s;
    unordered_map<int, char> u;
    unordered_map<char, int> v;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        cin >> m;
        for(int j=0; j<m; j++) {
            cin >> s;
            u.clear();
            v.clear();
            if(s.size() != n) {
                cout << "NO" << endl;
                continue;
            }
            bool ans = true;
            for(int i=0; i<n; i++) {
                if(u.find(a[i]) == u.end()) {
                    u[a[i]] = s[i];
                } else if(u[a[i]] != s[i]) {
                    ans = false;
                    break;
                }
                if(v.find(s[i]) == v.end()) {
                    v[s[i]] = a[i];
                } else if(v[s[i]] != a[i]) {
                    ans = false;
                    break;
                }
            }
            if(ans) cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }
}