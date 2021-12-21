/*
    Author : Baptiste Prévost

    Idea : 
        - Overall very simple, successive euclidian divisions
        - Result may be +-1 correct, as 4 can be separated in (1,3) and (2,2)
*/

#include <iostream>
using namespace std;

int main() {
    unsigned int t, n, c[1000];
    unsigned int p1, p2, p3;
    cin >> t;
    while(t--) {
        cin >> n;
        p1 = 0; p2 = 0; p3 = 0;
        for(unsigned int i = 0; i<n; i++) cin >> c[i];

        unsigned int q1=0, q2=0, q3=0;
        bool need1=false, need2=false, need3=false, need1_3=false;
        for(unsigned int i = 0; i<n; i++) {
            q3 = c[i]/3;
            q2 = (c[i]-3*q3)/2;
            q1 = c[i]-3*q3-2*q2;
            if(q3>p3) {
                p3=q3;
                // cout << "new p3 is " << p3 << endl;
            }
            if(q2 > p2) {
                p2 = q2;
                // cout << "new p2 is " << p2 << endl;
            }
            if(q1 > p1) {
                p1 = q1;
                // cout << "new p1 is " << p1 << endl;
            }

            if(c[i]==1) need1=true;
            if(c[i]==3) need3=true;
            if(q2>0) need2=true;
            if(q1>0 && q3>0) need1_3=true;
        }
        unsigned int res = p1+p2+p3;
        if(need2 && need1_3 && !need1 && !need3) res--;
        cout << res << endl;
    }
    return 0;
}