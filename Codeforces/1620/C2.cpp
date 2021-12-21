/*
    Author : Baptiste Prévost

    Idea : 
        - Messy idea
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int t, n, k;
    string s, seq;
    unsigned long long x;
    getline(cin, s);
    t = stoi(s);
    while(t--) {
        string ret = "";
        getline(cin, s, ' ');
        n = stoi(s);
        getline(cin, s, ' ');
        k = stoi(s);
        getline(cin, s);
        x = stoi(s)-1;
        getline(cin, seq);

        int index = 0;
        while(index<n) {
            if(seq[index]=='a') {
                ret='a'+ret;
            } else {
                int temp = index;
                while(temp + 1 < n && s[temp + 1] == s[index]) {
                    temp += 1;
                }
                unsigned long long cur = (temp-index+1)*k + 1;
                for(unsigned long long int z = 0; z < x%cur; z++) ret ='b'+ret;
                x =  x/cur;
                index = temp;
            }
            index++;
        }
        cout<<ret<<endl;
    }
    
    return 0;
}