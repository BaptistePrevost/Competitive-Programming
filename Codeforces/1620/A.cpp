/*
    Author : Baptiste Prévost

    Idea : 
        - Only inconsistent arrays contains one and only one N
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t, n;
    string s;
    getline(cin, s);
    t = stoi(s);
    while(t--) {
        n = 0;
        getline(cin, s);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'N') {
                n++;
            }
        }
        if(n==1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}