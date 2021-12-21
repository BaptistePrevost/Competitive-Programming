/*
    Author : Baptiste Prévost

    Idea : 
        -
        -
*/

#include <iostream>
using namespace std;

int main() {
    unsigned int t, n, c2, c3, c6, i;
    cin>>t;
    while(t--) {
        c2=0; c3=0; c6=0;
        cin >> n;

        i=1;
        while(i*i<=n) i++;
        c2=i;
        i=1;
        while(i*i*i<=n) i++;
        c3=i;
        i=1;
        while(i*i*i*i*i*i<=n) i++;
        c6=i;

        cout<<c2+c3-c6-1<<endl;
    }
    return 0;
}