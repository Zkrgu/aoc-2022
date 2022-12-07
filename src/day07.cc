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

	string s,s1,s2,ps;
	deque<string> path = {""};
	unordered_map<string,ll> m;
	ll sum = 0;
	while(getline(cin,s)) {
		s1 = s.substr(0,s.find(" "));
		s.erase(0,s.find(" ")+1);
		s2 = s.substr(0,s.find(" "));
		s.erase(0,s.find(" ")+1);

		if(s1 == "$") {
			if(s2 == "cd"){
				if(s == "/") continue;
				ps = "";
				for(auto p : path) {
					ps += p + '/';
					m[ps] += sum;
				}
				sum = 0;
				if(s == "..") path.pop_back();
				else path.pb(s);
			}
		}
		else if(s1 != "dir"){
			sum += stoll(s1);
		}
	}
	ps = "";
	for(auto p : path) {
		ps += p + '/';
		m[ps] += sum;
	}
	ll p1 = 0, p2 = 30000000;
	for(auto x : m) {
		if(x.second <= 100000) p1 += x.second;
		if(m["/"] - x.second <= 70000000 - 30000000 && min(p2, x.second) == x.second) p2 = x.second;
	}
	cout << p1 << "\n" << p2;
}
