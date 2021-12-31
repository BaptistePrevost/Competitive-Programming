#include <iostream>
using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); i++)

const int N=5010,mod=998244353;

inline int inc(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int dec(int x,int y){return x-y<0?x-y+mod:x-y;}

int n,k,m,pos[N],c[N][N];
string a;

int main(){
	cin>>n>>k>>a;
    a=" "+a;
	if(!k){cout<<1<<'\n';return 0;}
	for(int i=1;i<=n;++i)if(a[i]=='1') pos[++m]=i;
	if(m<k){cout<<1<<'\n';return 0;}

	for(int i=0;i<=n;++i){
		c[i][0]=1;
		for(int j=1;j<=i;++j)
			c[i][j]=inc(c[i-1][j],c[i-1][j-1]);
	}
    
	pos[0]=0,pos[m+1]=n+1;
	int ans=0;
	for(int i=1;i<=m-k+1;++i)ans=inc(ans,c[pos[i+k]-pos[i-1]-1][k]);
	for(int i=2;i<=m-k+1;++i)ans=dec(ans,c[pos[i+k-1]-pos[i-1]-1][k-1]);
	cout<<ans<<'\n';
}