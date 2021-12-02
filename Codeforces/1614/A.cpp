/*
    Author : Baptiste Prévost

    Idea : 
        - Simple greedy algorithm

*/

#include <iostream>
#include <list>
using namespace std;

int main() {
    int t;
    int n,l,r,k;
    int temp, total, price;
    scanf("%i", &t);
    while(t--) {
        list<int> c;
        total = 0; price = 0;
        scanf("%i %i %i %i", &n, &l, &r, &k);
        for(int i = 0; i < n; i++) {
            scanf("%i", &temp);
            if(temp >= l && temp <=r) c.push_back(temp); 
        }
        c.sort();
        
        list<int>::iterator it = c.begin();
        price += *it;
        while(price <= k && it != c.end()) {
            total++;
            it++;
            price+=*it;
        }

        printf("%i\n", total);
    }

    return 0;
}