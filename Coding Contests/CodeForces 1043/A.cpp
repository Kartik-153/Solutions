#include<bits/stdc++.h>
using namespace std;

void solve(int n, string a, int m, string b, string c) {
	string res = a;
	for(int i = 0; i < c.size();i++) {
		if(c[i] == 'V') 
			res = b[i] + res;
		else if(c[i] == 'D')
			res = res + b[i];
	}
	cout << res << endl;
}

int main() {
	
	int t = 0;
	cin >> t;
	while(t--) {
		int n, m;
		string a, b, c;
		cin >> n >> a >> m >> b >> c;
		solve(n, a, m, b, c); 
	}
	return 0;
}

