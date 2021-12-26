/*
    Author : Baptiste Prévost

    Idea : 
        - Count the right number of big and little tables
        - Shift the players such that the first player on a big table ends on a small table.
*/

#include <iostream>
#include "math.h"
#include <vector>
using namespace std;

int main() {
    int t, k, n, m;

    cin>>t;
    while(t--) {
        cin >> n >> m >> k;

        int player=0;
        while(k--) {
            for(int table=0; table<m; table++) {
                int size = n/m;
                if(table <  n%m) {
                    size++;
                }
                cout << size;
                for(int j=0; j<size; j++) {
                    cout << " " << (player++)%n + 1;
                }
                cout << endl;
            }
            player = (player + (n % m) * ((n + m - 1) / m))%n;
        }
        cout << endl;

    }
    return 0;
}