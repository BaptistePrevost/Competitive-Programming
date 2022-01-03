/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int main() {
    int t, k, n;
    cin >> t;

    while(t--) {
        cin >> n >> k;

        if(2*k-1> n) {
            cout << "-1" << endl;
            continue;
        }

        cout << 'R';
        forn(i, n-1) cout << '.';
        cout << endl;

        forn(i, k-1) {
            forn(j, n) cout << '.';
            cout << endl;
            forn(j, 2*(i+1)) cout << '.';
            cout << 'R';
            forn(j, n-2*(i+1)-1) cout << '.';
            cout << endl;
        }
        forn(i, n-2*(k-1)-1){
            forn(j, n) cout << '.';
            cout << endl;
        }
    }

    return 0;
}
