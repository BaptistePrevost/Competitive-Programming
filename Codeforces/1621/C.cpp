/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
#include <list>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int count, p[10001];
bool done[10001];
list<int> cycle;

int main() {
    int t, n, index, q, a, length, cycleCount;
    cin >> t;

    while(t--) {
        cin >> n;
        for(int i = 1; i <=n; i++) done[i] = false;

        count = 0;
        index = 1;
        cycleCount = 0;
        while(count < n) {
            cycle.clear();
            while(done[index]) index++; //find first free index

            q = index;
            cycle.push_back(a);

            cout << "? " << q << endl << flush;
            cin >> a;

            cout << "? " << q << endl << flush;
            cin >> a;
            length = 1;
            cycle.push_back(a);

            while(a != index) {
                cout << "? " << q << endl << flush;
                cin >> a;
                length++;
                cycle.push_back(a);
            }

            //store result
            int cur1 = cycle.front(), cur2 = 0;
            cycle.pop_front();


            forn(i, length) {
                cur2 = cycle.front();
                p[cur1] = cur2;
                done[cur1] = true;
                cur1 = cur2;
                cycle.pop_front();
            }

            count += length;
            cycleCount ++;
        }
        
        cout << "!";
        for(int i=1; i<=n; i++) cout << " " << p[i];
        cout << endl << flush;
    }

    return 0;
}
