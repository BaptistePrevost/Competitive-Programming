/*
    Problem : https://codeforces.com/contest/2013/problem/C
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <string>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;

    int n;
    int code;
    string s;
    while(t--) {
        cin >> n;
        
        s = "0";
        bool addingInFront = true;
        cout << "? " << s << endl;
        cin >> code;
        if(code == 0) {
            // Only 1s
            cout << "! ";
            for(int i=0; i<n; i++) cout << 1;
            cout << endl;
        } else {
            int i;
            for(i=0; i<n-1; i++) {
                if(addingInFront) {
                    cout << "? " << s << "0" << endl;
                    cin >> code;
                    if(code == 0) {
                        cout << "? " << s << "1" << endl;
                        cin >> code;
                        if(code == 0) {
                            addingInFront = false;
                            i--;
                        } else {
                            s.append("1");
                        }
                    } else {
                        s.append("0");
                    }
                } else {
                    cout << "? 0" << s << endl;
                    cin >> code;
                    if(code == 0) {
                        s.insert(0, "1");
                    } else {
                        s.insert(0, "0");
                    }
                }
            }
            cout << "! " << s << endl;
        }
    }
}
