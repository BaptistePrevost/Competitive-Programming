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
        vector<pair<unsigned long long int, unsigned long long int> > l;
        getline(cin, s, ' ');
        n = stoi(s);
        getline(cin, s, ' ');
        k = stoi(s);
        getline(cin, s);
        x = stoi(s)-1;
        getline(cin, seq);
        
        unsigned long long int b = 0;
        unsigned long long int a = 0;
        for(int i = n-1; i>=0; i--) {
            if(seq[i] == 'a') {
                if(b>0) {
                    l.push_back(make_pair(b, a));
                    a=0;
                }
                b = 0;
                a+=1;
            } else {
                b++;
            }
        }
        if(b>0) {
                l.push_back(make_pair(b, a));
                a=0;
        }

        unsigned long long int index = 0;
        unsigned long long int decount = l[0].first*k + 1;
        unsigned long long int count = 1;
        vector<unsigned long long int > temp;
        temp.push_back(count);

        while(decount <= x && index < l.size()-1) {
            temp.push_back(count);
            count = decount;
            index++;
            decount*=l[index].first*k;
        }

        //With the current index, x condition is fulfilled, or above
        unsigned long long int bs = x/count;

        for(unsigned long long int i = 0; i < a; i++) cout<<"a";
        if(decount > x) {
            for(unsigned long long int i = l.size()-1; i >= index+1; i--) {
                for(unsigned long long int j = 0; j < l[i].second; j++) cout<<"a";
                if(i==0) break;
            }
        }


        for(unsigned long long int i = 0; i < bs; i++) cout<<"b";
        for(unsigned long long int i = 0; i < l[index].second; i++) cout<<"a";
        index--;
        
        x-=bs*count;

        unsigned long long int current;
        while(x>1) {
            current = temp.back();
            count = current;
            temp.pop_back();
            bs = x/count;
            x-=bs*count;
            for(unsigned long long int i = 0; i < bs; i++) cout<<"b";
            for(unsigned long long int i = 0; i < l[index].second; i++) cout<<"a";
            index--;
        }

        cout << endl;

    }
    
    return 0;
}