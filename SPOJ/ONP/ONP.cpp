/*
    Author : Baptiste Prévost

    Idea : 
        - Simple recursive algorithm
*/

#include <iostream>
#include <string>

using namespace std;

string a(string s) {
    int size = s.length();
    string members[3];

    if(size == 3) {
        members[0] = s[0];
        members[1] = s[1];
        members[2] = s[2];
    }
    else {
        int index = 0;
        for(int i = 0; i < size; i++) {
            if(s[i] == '(') {
                int j = i+1;
                int countP = 1;
                while(countP != 0) {
                    if(s[j] == '(') countP ++;
                    if(s[j] == ')') countP--;
                    j++;
                }
                members[index++] = a(s.substr(i+1, j-i-2));
                i=j-1;
            } else {
                members[index++] = s[i];
            }
        }
    }
    return members[0] + members[2] + members[1];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string f;
        cin >> f;
        cout << a(f) << endl;
    }
    return 0;
}