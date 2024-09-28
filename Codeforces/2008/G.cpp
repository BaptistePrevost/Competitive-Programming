/*
    Problem : https://codeforces.com/contest/2008/problem/G
    Author : Baptiste Prévost
    Subjects : Number theory, gcd, mex

    Idea : For the given array n, the idea is to determine what is the set of different values that can be generated.
    The operations allowed can build the Euclide algorithm. For any pair of integers, it can yield the gcd.
    One can first compute the gcd "a" of the array ; it can then be transformed to an array with values [0, a, 2*a, ..., (n-1)*a]
    It is the minimal array of distinct values obtainable. It is then easy to obtain the mex in O(1).

    Complexity : nlogn
*/

#include <iostream>
#include <vector>

typedef unsigned long long ull;
const ull MAXN = 20009;

using namespace std;

ull custom_pgcd(ull u, ull v) {
    while(u > 0) {
        if(u < v) swap(u, v);
        u = u%v;
    }
    return v;
}

int main() {
    ull t, n, k, a, b;

    cin >> t;

    while(t--) {
        cin >> n >> k;
        cin >> a;
        for(ull i=0; i<n-1; i++) {
            cin >> b;
            a = custom_pgcd(a, b);
        }

        if(n == 1) {
            if(k <= a) {
                cout << k-1 << endl;
            } else {
                cout << k << endl;
            }
        } else {
            if(k <= (a-1)*(n-1)) {
                cout << ((k-1)/(a-1))*a + ((k-1)%(a-1)) + 1 << endl;
            } else {
                cout << (k-1)+n << endl;
            }
        }
        

    }

}