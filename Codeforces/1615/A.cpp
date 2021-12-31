#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int a[101];
int main() {
    int t, n, a, total;
    cin >> t;

    while(t--) {
        total=0;
        cin >> n;
        forn(i, n) {
            cin >> a;
            total += a;
        }

        (total%n == 0) ? cout << '0' << endl : cout << '1' << endl;


    }

    return 0;
}
