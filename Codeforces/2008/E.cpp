#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200009;

int main() {
    int t, n;
    string s;

    cin >> t;

    vector<vector<int>> cumulatedSum(26, vector<int>(MAXN));
    int maxEven, maxOdd, cutBest;
    int evenCharBefore, evenCharAfter;
    int oddCharBefore, oddCharAfter;

    while(t--) {
        cin >> n;
        cin >> s;

        if(n==1) {
            cout << "1" << endl;
            continue;
        } else if (n==2) {
            cout << "0" << endl;
            continue;
        }

        for(char c='a'; c<='z'; c++) {
            for(int i=0; i<n; i++) {
                if(i >= 2) cumulatedSum[c-'a'][i] = cumulatedSum[c-'a'][i-2] + (s[i] == c);
                else cumulatedSum[c-'a'][i] = (s[i] == c);
            }
        }
        
        if(n%2 == 0) {
            maxEven = 0; maxOdd = 0;
            for(int c=0; c<26; c++) {
                maxEven = max(maxEven, cumulatedSum[c][n-2]);
                maxOdd = max(maxOdd, cumulatedSum[c][n-1]);
            }
            cout << n-maxEven-maxOdd;
        } else {
            cutBest = MAXN;
;
            for(int cut=0; cut<n; cut++) {
                for(int evenChar=0; evenChar<26; evenChar++) {
                    if(cut%2) {
                        evenCharBefore = cumulatedSum[evenChar][cut-1];
                        evenCharAfter = cumulatedSum[evenChar][n-2] - cumulatedSum[evenChar][cut];
                    } else {
                        if(cut>0) evenCharBefore = cumulatedSum[evenChar][cut-2];
                        else evenCharBefore = 0;

                        if(cut>0) evenCharAfter = cumulatedSum[evenChar][n-2]  - cumulatedSum[evenChar][cut-1];
                        else evenCharAfter = cumulatedSum[evenChar][n-2];
                    }
                    for(int oddChar=0; oddChar<26; oddChar++) {
                        if(cut%2) {
                            if(cut>1) oddCharBefore = cumulatedSum[oddChar][cut-2];
                            else oddCharBefore = 0;

                            oddCharAfter = cumulatedSum[oddChar][n-1] - cumulatedSum[oddChar][cut-1];
                        } else {
                            if(cut>0) oddCharBefore = cumulatedSum[oddChar][cut-1];
                            else oddCharBefore = 0;

                            oddCharAfter = cumulatedSum[oddChar][n-1] - cumulatedSum[oddChar][cut];
                        }

                        cutBest = min(cutBest, n-evenCharBefore-evenCharAfter-oddCharBefore-oddCharAfter);
                    }
                }
            }
            cout << cutBest;
        }
        cout << endl;
    }
}