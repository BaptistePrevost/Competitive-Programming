/*
    Author : Baptiste Prévost

    Idea : 
        - The main idea is to start to mirror the second half of the word with the first part.
        - I treated odd and even cases differently, they need different processing.
        - incrementAndPropagate make sure to propagate efficiently the addition when incrementing a 9 to 0
*/


#include <iostream>
#include <string>
using namespace std;

string incrementAndPropagate(string s, long long i) {
    while(s[i]==57) {
        s[i] = 48;
        i--;
    }
    s[i]++;
    return s;
}

bool scanForError(string s, long long size) {
    for(long long j = size/2 + 1; j < size; j++) {
        if(s[j] < s[size-j-1]) return false;
        if(s[j] > s[size-j-1]) return true;
    }
    return false;
}


int main() {
    int t;
    string useless;
    scanf("%i", &t);
    getline(cin,useless);
    while(t--) {
        string nb;
        getline (cin,nb);
        long long size = nb.length();
        if(!isdigit(nb[nb.length()-1])) size--;
        
        //add 1 and deal with case re'9+'
        long long ind = size-1;
        while(nb[ind] == 57) {
            nb[ind] = 48;
            ind--;
        }
        if(ind<0) {
            nb[size-1]='1';
            cout << "1";
        } else {
            nb[ind]+=1;
            if(size%2 == 0) {
                if(nb[size/2 - 1] < nb[size/2]) {
                    nb[size/2 - 1]+=1; //cannot be a 9
                } else if(nb[size/2 - 1] == nb[size/2]) {
                    
                    if(scanForError(nb, size)) {
                        nb = incrementAndPropagate(nb, size/2-1);  
                    }
                }
                for(long long j = size/2; j < size; j++) {
                    nb[j] = nb[size-j-1];
                }
            } else {            
                if(scanForError(nb, size)) {
                    nb = incrementAndPropagate(nb, size/2);  
                }
                for(long long j = size/2 + 1; j < size; j++) {
                    nb[j] = nb[size-j-1];
                }
            }
        }

        cout << nb << endl;
    }
    printf("\n");

    return 0;
}