#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> a(n+1, vector<bool>(m+1));
	vector<vector<int>> v(n+2, vector<int>(m+2));
	char c;
	for(int i=1; i<=n; i++) {
    	for(int j=1; j<=m; j++) {
    	    cin >> c;
			a[i][j] = c=='1';
	    }
	}
	int q, x1, y1, x2, y2;
	cin >> q;
	while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
	    v[x1][y1]++;
	    v[x2+1][y1]--;
	    v[x1][y2+1]--;
	    v[x2+1][y2+1]++;
	}
	
	for(int i=1; i<=n; i++) {
    	for(int j=1; j<=m; j++) {
    	    v[i][j] += v[i][j-1];
	    }
	}
	for(int j=1; j<=m; j++) {
		for(int i=1; i<=n; i++) {
    	    v[i][j] += v[i-1][j];
	    }
	}
	for(int i=1; i<=n; i++) {
    	for(int j=1; j<=m; j++) {
			if(v[i][j]&1) cout << (!a[i][j]);
			else cout << a[i][j];
	    }
		cout << endl;
	}
}
