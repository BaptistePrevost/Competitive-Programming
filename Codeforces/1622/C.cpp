/*
    Author : Baptiste Prévost

    Idea :
        - The best greedy strategy is to decrease the smallest number, and set the highest numbers to this minimized smallest value
        - We need to find a compromise between lowering the minimal value and setting high numbers to this low value
        - To do so, we use bruteforce, and iterate over the number of equalizing steps
*/

#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long

int main() {
    int t;
    ll decrease, k, res, sum, a[200001], n;
    cin >> t;
    
    while(t--) {
        res = -1; decrease=0; sum=0;
        cin >> n >> k;
        forn(i, n) {
            cin >> a[i];
            sum+=a[i];
        }

        sort(a, a+n);

        
        ll temp=sum-a[0];
        if(k < sum) {
            
            forn(i, n) {
                //calculate cost when we chose to equalize i indice
                if(i > 0) temp-=a[n-i];

                decrease = a[0] - floor((double(k)-double(temp))/double(i+1));
                if(decrease < 0) decrease = 0;
                if(res == -1 || decrease + i < res) {
                    res = decrease+i;
                }
            }

        }
        
        if(res==-1) res=0;
        cout << res << endl;
    }

    return 0;
}
