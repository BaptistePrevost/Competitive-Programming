#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int oc = count(s.begin(), s.end(), '1');
        if (sqrt(n)*4-4==oc) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}