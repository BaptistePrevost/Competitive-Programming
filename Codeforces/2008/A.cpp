#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        b = b%2;
        if(a%2==0) {
            if(b & a<2)cout << "NO";
            else cout << "YES";
        } else cout << "NO";

        cout << endl;
    }
}