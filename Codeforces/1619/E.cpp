/*
    Author : Baptiste Prévost

    Idea : 
        - Dynamic programming : If MEX i not reachable, then MEX i+1 isn't. 
        - Moreover, the building cost for i+1 is calculated from the one for i
*/

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    int t, n;
    long long a[200001];
    long long occurences[200001];
    cin >> t;
    while(t--) {
        fill(occurences, occurences+200001, 0);
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            occurences[a[i]]++;
        }

        sort(a, a+n);
        long long index = 0, mex = 0, buildCost = 0, last=-1;
        list<long long> unused;
        while(mex<=n) {
            while(index < n && a[index]<mex) {
                if(a[index]==last) unused.push_back(last);
                last = a[index];
                index++;
            }
            if(index >= mex) {
                if(mex>0 && occurences[mex-1] == 0) {
                    buildCost += mex - 1 - unused.back();
                    unused.pop_back();
                }
                
                cout << buildCost + occurences[mex] << " ";
            }
            else break;
            mex++;
        }
        while(mex<=n) {
            cout << "-1 ";
            mex++;
        }
        cout << endl;
    }


    return 0;
}