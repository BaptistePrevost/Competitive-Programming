/*
    Author : Baptiste Prévost

    Idea : 
        -
        -
*/

#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin>>t;
    string S, res;
    while(t--) {
        res="YES";
        cin>>S;
        if(int(S.size())%2 == 1) {
            res="NO";
        } else {
            n = int(S.size())/2;
            for(int i=0; i<n; i++) {
                if(S[i] != S[i+n]) res="NO";
            }
        }
        cout<<res<<endl;
    }
    return 0;
}