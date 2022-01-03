/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int n, m, rb, rd, cb, cd;
int ansH, ansV;

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m >> rb >> cb >> rd >> cd;
        ansH = (rb>rd) ? 2*(n-rb)+rb-rd : rd-rb;
        ansV = (cb>cd) ? 2*(m-cb)+cb-cd : cd-cb;
        ansV = (ansH>ansV) ? ansV : ansH;
        cout << ansV << endl;
    }



    return 0;
}
