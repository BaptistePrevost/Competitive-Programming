#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

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