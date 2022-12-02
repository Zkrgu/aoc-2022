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

	char o, m;
	int d, s;
	ll p1 = 0, p2 = 0;
	while(cin >> o >> m) {
		o -= 65;
		m -= 88;

		p1 += m+1;
		s = ((1 + m - o)%3+3)%3;
		p1 += 3*s;

		m = ((o+m-1)%3+3)%3;
		p2 += m+1;
		s = ((1 + m - o)%3+3)%3;
		p2 += 3*s;
	}
	cout << p1 << "\n" << p2;
}
