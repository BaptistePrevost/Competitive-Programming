/*
    Author : Baptiste Prévost

    Idea : 
        - A problem occures when a is too long to find a satisfying b
*/

#include <iostream>
#include "math.h"
using namespace std;

int main() {
    int t, rank=0, m, n, p;
    bool fail;
    uint64_t a, b, s;
    cin>>t;

    while(t--) {
        b=0;
        rank=0;
        fail=false;
        cin >> a >> s;
        while(a != 0 || s != 0) {
            m = a-(a/10)*10;
            n = s-(s/10)*10;
            if(m>n) {
                s/=10;
                if(s-(s/10)*10 != 1) {
                    fail=true;
                    break;
                }
                p=10+n-m;
            }
            else p=abs(n-m);
            b+=pow(10, rank)*p;
            s/=10;
            a/=10;
            rank++;
        } 
        fail ? cout<<-1<<endl : cout<<b<<endl;
    }


    return 0;
}