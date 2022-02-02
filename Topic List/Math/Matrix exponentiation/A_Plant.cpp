/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n)  for (int i = 0; i < int(n); i++)
typedef long long int ll;
const ll M=1e9+7;

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


const int MOD = 1000000007;

struct Matrix {
    int n, m;
    vector<vector<int>> a;
    Matrix(){}
    Matrix(int _n, int _m) {n=_n; m=_m; a.assign(n, vector<int>(m,0));}
    Matrix(vector< vector<int> > v) {n=v.size(); m = n ? v[0].size() : 0; a=v;}
    inline void make_unit() {
        assert(n==m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) a[i][j] = i==j;
        }
    }

    inline Matrix operator + (const Matrix &b) {
        assert(n==b.n && m==b.m);
        Matrix ans = Matrix(n,m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % MOD;
            }
        }
        return ans;
    }

    inline Matrix operator - (const Matrix &b) {
        assert(n==b.n && m==b.m);
        Matrix ans = Matrix(n,m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans.a[i][j] = (a[i][j] - b.a[i][j] + MOD) % MOD;
            }
        }
        return ans;
    }

    inline Matrix operator * (const Matrix &b) {
        assert(m==b.n);
        Matrix ans = Matrix(n, b.m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<b.m; j++) {
                for(int k=0; k<m; k++) {
                    ans.a[i][j] = (ans.a[i][j] + 1LL*a[i][k]*b.a[k][j] % MOD) % MOD;
                }
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
    ll n;
    cin >> n;
    Matrix a(2,1), m(2,2);
    a.a[0][0]=1; a.a[1][0]=0;
    m.a[0][0]=3; m.a[0][1]=1;
    m.a[1][0]=1; m.a[1][1]=3;
    a=m.pow(n)*a;
    cout << a.a[0][0]%MOD;
    return 0;
}
