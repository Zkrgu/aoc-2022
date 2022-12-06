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
	char c;
	vector<char> cq;
	set<char> cs;
	cin >> s;

	int i=1,n;
	ll p1=0,p2=0;
	while(1) {
		c = s[i-1];
		cq.pb(c);

		n = sz(cq);
		cs.clear();

		if(n >= 4) {
			cs.insert(end(cq)-4, end(cq));
			if(p1 == 0 && sz(cs) == 4) {
				p1 = i;
			}
			cs.insert(end(cq)-14, end(cq)-4);
			if(sz(cs)==14){
				p2 = i;
				break;
			}
		}
		++i;
	}

	cout << p1 << "\n" << p2;
}
