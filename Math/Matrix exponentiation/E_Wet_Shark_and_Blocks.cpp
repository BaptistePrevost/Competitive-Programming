/*
    Author : Baptiste Prévost

    Super interesting problem. Matrix exponentiation can also be used for combinatorics even with modulos.

    Idea :
        - First count the occurences of each digit.
        - To build the matrix M, we iterate i from 0 to x-1, then a digit d from 0 to 9.
            M[i][j]!=0 means that we can pick a digit in a block at the current step to make the resulting number modulo x go from i to j.
        - in our case, i=i, and j=(10*i + d)%x. We add to M[i][j] the number of occurences of d
        - The matrix M is all set for exponentiation. The result is M**b[0][k], which is literaly the number of ways to obtain a number so that modulo x = k after b steps.
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n)  for (int i = 0; i < int(n); i++)
typedef long long int ll;
const ll MOD=1e9+7;

#define sz(x)       ((ll) (x).size())
#define all(x)      (x).begin(), (x).end()
#define pll         pair<ll,ll>
#define vl          vector<ll>
#define ff          first
#define ss          second
#define pb          push_back
#define pp          pop_back
#define frr(i,j,k)  for(ll i=j; i<k; i++)
#define andar(x)    for(ll&i:x) cin>>i;
#define bahar(x)    for(ll&i:x) cout<<i<<' ';

struct Matrix {
    long long n, m;
    vector<vector<long long>> a;
    Matrix(){}
    Matrix(long long _n, long long _m) {n=_n; m=_m; a.assign(n, vector<long long>(m,0));}
    Matrix(vector< vector<long long> > v) {n=v.size(); m = n ? v[0].size() : 0; a=v;}
    inline void make_unit() {
        assert(n==m);
        for(long long i=0; i<n; i++) {
            for(long long j=0; j<n; j++) a[i][j] = i==j;
        }
    }

    void display() {
        for(long long i=0; i<n; i++) {
            for(long long j=0; j<m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    inline Matrix operator + (const Matrix &b) {
        assert(n==b.n && m==b.m);
        Matrix ans = Matrix(n,m);
        for(long long i=0; i<n; i++) {
            for(long long j=0; j<m; j++) {
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % MOD;
            }
        }
        return ans;
    }

    inline Matrix operator - (const Matrix &b) {
        assert(n==b.n && m==b.m);
        Matrix ans = Matrix(n,m);
        for(long long i=0; i<n; i++) {
            for(long long j=0; j<m; j++) {
                ans.a[i][j] = (a[i][j] - b.a[i][j] + MOD) % MOD;
            }
        }
        return ans;
    }

    inline Matrix operator * (const Matrix &b) {
        assert(m==b.n);
        Matrix ans = Matrix(n, b.m);
        for(long long i=0; i<n; i++) {
            for(long long j=0; j<b.m; j++) {
                for(long long k=0; k<m; k++) {
                    ans.a[i][j] = (ans.a[i][j] + 1LL*a[i][k]*b.a[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }

    inline Matrix distanceProduct(const Matrix &b) {
        //Used in Floyd-Marshall algorithm, but you have to non-existing edges to infinity
        assert(m==b.n);
        Matrix ans(a);
            for(long long i=0; i<n; i++) {
                for(long long j=0; j<n; j++) {
                    long long mini = 1e9+7;
                    for(long long k=0; k<m; k++) {
                        mini = min(mini, (a[i][k]+b.a[k][j])%MOD);
                    }
                    ans.a[i][j]=mini;
                }
            }
        return ans;
    }

    inline Matrix pow(long long k) {
        assert(n==m);
        Matrix ans(n,n), t=a; ans.make_unit();
        while(k) {
            if(k&1) ans = ans*t;
            t = t*t;
            k>>=1;
        }
        return ans;
    }

    inline Matrix& operator += (const Matrix& b) { return *this = (*this) + b;}
    inline Matrix& operator -= (const Matrix& b) { return *this = (*this) - b;}
    inline Matrix& operator *= (const Matrix& b) { return *this = (*this) * b;}
    inline bool operator == (const Matrix& b) { return a == b.a;}
    inline bool operator != (const Matrix& b) { return a != b.a;}
};

int main() {
    ll n, b, k, x;
    cin >> n >> b >> k >> x;
    int d, digits[10]{};
    forn(i, n) {
        cin >> d;
        digits[d]++;
    }
    Matrix a(x,x);
    forn(i, x) {
        forn(j, 10) {
            a.a[i][(10*i + j)%x]+= digits[j];
        }
    }
    a = a.pow(b);
    cout << ((a.a[0][k])%MOD);
    return 0;
}
