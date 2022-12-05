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
	string p1 ="", p2="";
	vector<stack<char>> ss,ss2;
	vector<string> l;
	while(getline(cin,s)) {
		if(s.empty()) break;
		l.pb(s);
	}

	char r;
	int n = sz(l);
	for(int i=n-2;i>=0;--i) {
		for(int j=0;!l[i].empty();++j){
			r = l[i][1];
			if(r != ' ') {
				if(i==n-2) ss.pb(stack<char>());
				ss[j].push(r);
			}
			l[i].erase(0,4);
		}
	}
	ss2 = ss;

	string _;
	int a,b,c;
	stack<char> m;
	while(cin >> _ >> a >> _ >> b >> _ >> c) {
		rep(i,0,a) {
			ss[c-1].push(ss[b-1].top());
			ss[b-1].pop();

			m.push(ss2[b-1].top());
			ss2[b-1].pop();
			if(i == a-1) while(!m.empty()) {
				ss2[c-1].push(m.top());
				m.pop();
			}
		}
	}
	for(auto stack : ss) p1 += stack.top();
	for(auto stack : ss2) p2 += stack.top();
	cout << p1 << "\n" << p2;
}
