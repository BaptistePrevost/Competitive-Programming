/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int ask(int i) {
    cout << "? " << i << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    int t, n, length, cycleCount;
    cin >> t;

    while(t--) {
        cin >> n;

        vector<int> p(n+1, -1);

        for(int i=1; i<=n; i++) {
            if(p[i]==-1) {
                vector<int> cycle;
                int goal = ask(i);
                int current = ask(i);
                cycle.push_back(current);
                while(current != goal) {
                    current = ask(i);
                    cycle.push_back(current);
                }

                forn(j, cycle.size()) p[cycle[j]] = cycle[(j+1)%cycle.size()];
            }
        }
        
        cout << "!";
        forn(i, n) cout << " " << p[i+1];
        cout << endl;
    }

    return 0;
}
