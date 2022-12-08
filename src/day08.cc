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

	string s;
	vector<vi> ts;
	vi t;
	while(getline(cin,s)){
		t.clear();
		while(!s.empty()) {
			t.pb(stoi(s.substr(0,1)));
			s.erase(0,1);
		}
		ts.pb(t);
	}

	ll p1 = (sz(ts)-1)*2+(sz(ts[0])-1)*2, p2 = 0;
	int a,b,c,d,m;
	rep(i,1,sz(ts)-1) rep(j,1,sz(ts[0])-1) {
		a=1, b=1, c=1, d=1;
		m = ts[i][j];
		while(i-a > 0 && m > ts[i-a][j]) ++a;
		while(i+b < sz(ts)-1 && m > ts[i+b][j]) ++b;
		while(j-c > 0 && m > ts[i][j-c]) ++c;
		while(j+d < sz(ts[0])-1 && m > ts[i][j+d]) ++d;
		if((i-a == 0 && ts[0][j] < m) ||
			(i+b == sz(ts)-1 && ts[i+b][j] < m) ||
			(j-c == 0 && ts[i][0] < m) ||
			(j+d == sz(ts[0])-1) && ts[i][j+d] < m) ++p1;
		if(a*b*c*d > p2) p2 = a*b*c*d;
	}
	cout << p1 << "\n" << p2;
}
