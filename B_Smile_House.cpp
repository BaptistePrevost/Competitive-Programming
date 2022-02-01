/*
    Author : Baptiste Prévost

    This was so hard to me ... Thanks for the help I found on the codeforces blogs.
    
    Idea :
        - Inverted the weights, and compute the distance matrix of  
        - TLE is avoided using binary search
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n)  for (int i = 0; i < int(n); i++)
typedef long long int ll;
const ll M=1e9+7;

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

    void display() {
        for(long long i=0; i<n; i++) {
            for(long long j=0; j<m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
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

bool check(const Matrix &a) {
    frr(i, 0, a.n) if(a.a[i][i]<0) return true; 
    return false;
}

int main() {
    ll n, m, i, j, c, d;
    cin >> n >> m;

    Matrix a(n,n);

    frr(i,0,n) {
        frr(j,0,n) {
            if(i!=j) a.a[i][j]=M;
        }
    }

    while(m--) {
        cin >> i >> j >> c >> d;
        --i; --j;
        a.a[i][j]=-c;
        a.a[j][i]=-d;
    }

    Matrix pows[9];
    pows[1]=a;
    for(int i=2; i<9; i++) {
        pows[i]=distanceProduct(pows[i-1], pows[i-1], M); 
    }
  
    ll mid, high=n+1, low=2;
    bool found=false;
    Matrix distanceMatrix(n,n);
    while(low <= high) {
        distanceMatrix.a = a.a;
        mid=(high+low) >> 1;
        ll distance = mid-1, expo = 256, expoIndex = 9;
        // cout << "mid is " << mid << endl;
        while(expo > 0) {
            while(distance/expo) {
                // cout << expoIndex << endl;
                distanceMatrix = distanceProduct(distanceMatrix, pows[expoIndex], M);
                distance -= expo;
            }
            expoIndex--;
            expo /= 2;
        }
        // distanceMatrix.display();
        if(check(distanceMatrix)) high=mid-1;
        else low=mid+1;
    }
    if(low >= n+1) low = 0;
    cout << low;
    return 0;
}