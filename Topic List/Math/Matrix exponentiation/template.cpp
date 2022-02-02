#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

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

Matrix distanceProduct(const Matrix &a, const Matrix &b, long long infinity) {
    //Used in Floyd-Marshall algorithm, but you have to non-existing edges to infinity
    assert(a.m==b.n);
    Matrix ans(a.a);
        for(long long i=0; i<a.n; i++) {
            for(long long j=0; j<a.n; j++) {
                long long mini = 1e9+7;
                for(long long k=0; k<a.m; k++) {
                    if(a.a[i][k]!=infinity && b.a[k][j]!=infinity) mini = min(mini, (a.a[i][k]+b.a[k][j])%MOD);
                }
                ans.a[i][j]=mini;
            }
        }
    return ans;
}