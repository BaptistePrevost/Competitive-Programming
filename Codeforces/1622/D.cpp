/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long

#define MOD 998244353

ll among(int k, int n) {
    if(k>n) return 0;
    if(k==0) return 1;
    if(k==1) return n;

    return among(k, n-1) + among(k-1, n-1);
}

vector<int> v;
int main() {
    int t, n, k;
    string s;
    cin >> t;
    ll res;
    
    while(t--) {
        v.clear();
        res = 1;
        cin >> n >> k;
        cin >> s;
        
        forn(i, n) {
            if(s[i] == '1') v.push_back(i);
        }

        if(v.size() < k || k == 0) {
            cout << '1' << endl;
            continue;
        }

        int before=0, inside=0, after=0;
        //first
        before = 0;
        inside = 0;
        forn(i, k-1) {
            inside += v[i+1] - v[i] - 1;
        }
        if(k<v.size()) after = v[k]-v[k-1]-1;
        // cout << "First / before " << before << ", inside : " << inside << ", after: " << after  << endl;
        res += (among(k, before + inside + after + k)-1)%MOD;
        // cout << k << " among " << before + inside + after + k<< endl;


        for(int i=1; i+k-1 < v.size()-1 ; i++) { //is n always > k ?
            // cout << "Loop /";
            before = inside;
            inside = after;
            after = v[i+k] - v[i+k-1] - 1;
            // cout << "before : " << before << "inside : " << inside << "after : " << after << endl;
            // cout << k << " among " << before + inside + after + k<< endl;
            res += among(k, before + inside + after + k)-1;
            res -= among(k-1, before+k-1)-1;
            res %= MOD;
            // cout << " before " << before << ", inside : " << inside << ", after: " << after  << endl;
        }

        //last
        before = inside;
        inside = after;
        after = n - 1 - v.back();
        res += among(k, before + inside + after + k)-1;
        // cout << k << " among " << before + inside + after + k << " is " << among(k, before + inside + after + k) << endl;
        res -= among(k-1, before+k-1)-1;
        res %= MOD;
        // cout << "before " << before << ", inside : " << inside << ", after: " << after  << endl;
        //!\\ Careful when reaching the end of the string

        cout << res << endl;

    }

    return 0;
}
