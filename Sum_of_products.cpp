/*
    Author : Baptiste Prévost

    Idea :
        - f(n+1) = 3*f(n)-f(n-1)-n
        - using Matrix from Math\Matrix exponentiation\template.cpp
        - Coulnd't have AC on SPOJ
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
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % M;
            }
        }
        return ans;
    }

    inline Matrix operator - (const Matrix &b) {
        assert(n==b.n && m==b.m);
        Matrix ans = Matrix(n,m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans.a[i][j] = (a[i][j] - b.a[i][j] + M) % M;
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
                    ans.a[i][j] = (ans.a[i][j] + 1LL*a[i][k]*b.a[k][j] % M) % M;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t, n;
    cin >> t;
    Matrix a(4,1), m(4,4);
    a.a[0][0]=1; a.a[1][0]=0; a.a[2][0]=2; a.a[3][0]=1;

    m.a[0][0] = 3; m.a[0][1] = -1; m.a[0][2] = 1; m.a[0][3] = 0;
    m.a[1][0] = 1; m.a[1][1] = 0; m.a[1][2] = 0; m.a[1][3] = 0;
    m.a[2][0] = 0; m.a[2][1] = 0; m.a[2][2] = 1; m.a[2][3] = 1;
    m.a[3][0] = 0; m.a[3][1] = 0; m.a[3][2] = 0; m.a[3][3] = 1;

    while(t--) {
        cin >> n;
        ll ans;
        if(n==1) ans=0;
        else {
            a = m.pow(n-2)*a;
            ans = a.a[0][0];
        }   
        cout << ans%M << endl;
    }
    return 0;
}