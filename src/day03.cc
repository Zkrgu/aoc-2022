#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

int getValue(char c) {
	if(c > 'Z') return c -'a'+1;
	return c-'A'+27;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	string s;
	set<char> l,r;
	set<char> s2[5];
	int i = 0,n;
	ll p1 = 0, p2 = 0;
	vector<char> in;

	while(cin >> s){
		if(!(i%3)) fill(all(s2), set<char>());
		n = s.length();
		l = set<char>();
		r = set<char>();
		for( char c : s.substr(0,n/2) ) l.insert(c);
		for( char c : s.substr(n/2)) r.insert(c);

		set_intersection(all(l), all(r), back_inserter(in));
		p1 += getValue(*(in.end()-1));
		
		for(char c : s) {
			s2[i%3].insert(c);
		}
		
		if(i%3 == 2) {
			set_intersection(all(s2[0]), all(s2[1]), inserter(s2[3], s2[3].begin()));
			set_intersection(all(s2[2]), all(s2[3]), inserter(s2[4], s2[4].begin()));
			for(auto c : s2[4]) p2 += getValue(c);
		}
		++i;
	}
	cout << p1 << "\n" << p2;
}
