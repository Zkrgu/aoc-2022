#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	freopen("input/day02", "r", stdin);

	char o, m;
	int d;
	ll p1 = 0, p2 = 0;
	while(cin >> o >> m) {
		o -= 65;
		m -= 88;

		p1 += m+1;
		d = ((o-m)%3+3)%3;

		if(d==2) p1 += 6;
		else if(d==0) p1 += 3;

		if(m==2) p2 += 7+((o+1)%3)%3;
		else if(m==1) p2 += 4+o;
		else p2 += 1+((o-1)%3+3)%3;
	}
	cout << p1 << "\n" << p2;
}
