#include <bits/stdc++.h>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

const ll MAXN = 200009;

vector<ll> c(26);

bool comp(char &c1, char &c2) {
    return c[c1-'a'] > c[c2-'a'];
}

int main() {
    ll t;
    cin >> t;
    ll n;
    string s;
    string alphabet;
    
    while(t--) {
        cin >> n;
        cin >> s;
        fill(c.begin(), c.end(), 0);
        for(ll i=0; i<n; i++) c[s[i]-'a']++;
        alphabet = "abcdefghijklmnopqrstuvwxyz";
        sort(alphabet.begin(), alphabet.end(), comp);
        // sort(c.rbegin(), c.rend());
        
        queue<char> q;
        for(int i=0; i<26; i++) q.push(alphabet[i]);
        while(q.size()) {
            char d = q.front();
            q.pop();
            if(!c[d-'a']) continue;
            c[d-'a']--;
            cout << d;
            q.push(d);
        }
        cout << endl;
    }
}