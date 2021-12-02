/*
    Author : Baptiste Prévost

    Idea : 
        -
        -
*/

#include <iostream>
#include <list>
using namespace std;

void displayInt(list<int> n) {
    while(n.size()) {
        printf("%i", n.back());
        n.pop_back();
    }
    cout << endl;
}

list<int> addition(list<int> a, list<int> b) {
    printf("add : \n");
    displayInt(a); displayInt(b);
    list<int>::iterator itA = a.begin();
    for(list<int>::iterator itB = b.begin(); itB != b.end(); itB++) {
        if(itA!=a.end()) {
            list<int>::iterator it3 = itA;
            *it3 = *itB + *itA;
            if(*it3 > 9) {
                *it3-=10;
                it3++;
                if(it3!=a.end()) {
                    *it3 += 1;
                } else {
                    a.push_back(1);
                }
            }
            itA++;
        } else {
            a.push_back(*itB);
        }
    }
    printf("Obtained: \n");
    displayInt(a);
    return a;
}

list<int> multiply(list<int> n, int i) { //general case, could be optimized
    printf("\nmultiply : \n");
    displayInt(n); printf("%i\n", i);
    list<int> ret;
    int degree = 0;
    for(list<int>::iterator it = n.begin(); it != n.end(); it++) {
            list<int> factor;
            int temp = *it * i;
            if(temp>9) factor.push_front(temp/10);
            factor.push_front(temp%10);
            for(int j = 0; j < degree; j++) factor.push_front(0);
            ret = addition(ret, factor);
            degree++;
        }
    printf("Obtained: \n");
    displayInt(ret);
    return ret;
}


list<int> factorial(list<int> n, int value) {
    if(n.size() == 1 && n.back() == 1) return n;
    else {
        list<int> m = n;
        list<int>::iterator itM = m.begin();
        *itM -= 1;
        if(*itM < 0) {
            while(*itM < 0) {
                *itM = 9;
                itM++;
                *itM -= 1;
            }
        } else itM ++;
        if(*itM == 0) m.pop_back();
        // cout << "n-1 : "; displayInt(m);
        return multiply(factorial(m, value-1), value);
    }

}


int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a,b;
        scanf("%lli", &a);
        b=a;
        list<int> n;
        do{
            n.push_back(a%10);
            a = a/10;
        } while(a);
        displayInt(factorial(n, b));
    }
    return 0;
}

// int main() {
//     long long a;
//     scanf("%lli", &a);
//     list<int> m;
//     do{
//         m.push_back(a%10);
//         a = a/10;
//     } while(a);

//     scanf("%lli", &a);
//     list<int> n;
//     do{
//         n.push_back(a%10);
//         a = a/10;
//     } while(a);

//     displayInt(addition(m,n));
    
// }