#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    string s;
    while(t--) {
        cin >> n;
        cin >> s;
        if(s[0] != s[n-1]) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}