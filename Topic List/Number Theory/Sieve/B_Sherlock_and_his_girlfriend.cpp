/*
    Author : Baptiste Prévost

    Idea :
        - La bidouille, exo simple
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> is_prime(100005, 0);

int sieve(int n) {
    /*
        Ignore the even numbers
    */
    int color=1;
    bool newColor;
    for(int i=2; i*i <= n; i++) {
        if(is_prime[i]==0) {
            newColor=false;
            for(int j=i*i; j<=n; j+=i) {
                if(is_prime[j]==0) {
                    is_prime[j]=color;
                    newColor=true;
                }
            }
            if(!newColor) color++;
        }
    }
    return color;
}
int main() {
    int n;
    cin >> n;
    if(n==1) {
        printf("1\n1");
        return 0;
    } else if (n==2) {
        printf("1\n1 1");
        return 0;
    }
    printf("%d\n", sieve(n+1)+1);
    for(int i=2; i<=n+1; i++) printf("%d ", is_prime[i]+1);
    return 0;
}
