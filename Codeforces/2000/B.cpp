#include <bits/stdc++.h>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, a;
    set<int> occupied;
    while(t--) {
        cin >> n;
        cin >> a;
        occupied.clear();
        occupied.insert(a);
        bool ans = true;
        for(int i=0; i<n-1; i++) {
            cin >> a;
            if(occupied.find(a-1) == occupied.end() && occupied.find(a+1) == occupied.end()) {
                ans = false;
            }
            occupied.insert(a);
        }
        if(ans) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}