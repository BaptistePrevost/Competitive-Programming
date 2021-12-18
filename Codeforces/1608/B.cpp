/*
    Author : Baptiste Prévost

    Idea : 
        - |a-b| <= 1 and a + b <= n-2
        - swap neighbour numbers to achieve the correct numbers
*/

#include <iostream>
using namespace std;

int main() {
    int t, n, a, b;
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        if(a+b > n-2 || abs(b-a) > 1) {
            cout << -1;
        } else {
            if(a==b) {
                cout << 1;
                for(int i = 0; i < a; i++) {
                    cout << ' ' << 2*(i+1) + 1 << ' ' << 2*(i+1); 
                }
                for(int j = 2*a + 1; j < n; j++) {
                    cout << ' ' << j+1;
                }
            } else if(a < b) {
                for(int i = 0; i < b; i++) {
                    cout << 2*(i+1) << ' ' << 2*(i+1) - 1 << ' ';
                }
                for(int j = 2*b; j < n; j++) {
                    cout << j+1 << ' ';
                }
            } else if(b < a) {
                for(int i = 0; i < n-(2*a); i++) {
                    cout << i+1 << ' ';
                }
                for(int j = n/2 - a; j < n/2; j++) {
                    cout << 2*(j+1) + n%2 << ' ' << 2*(j+1) - (1-n%2) << ' ';
                }
            }
        }
        cout << endl;
    }
    return 0;
}