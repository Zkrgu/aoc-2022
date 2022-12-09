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

	pair<int,int> d,d2;
	vector<pair<int,int>> ns(10,mp(0,0));
	set<pair<int,int>> v1 = {ns[0]}, v9 = {ns[9]};
	map<char,pair<int,int>> ds = {
		{'U', mp(0,-1)},
		{'D', mp(0,1)},
		{'L', mp(-1,0)},
		{'R', mp(1,0)}
	};

	char c;
	int n;
	while(cin >> c >> n) {
		d = ds[c];
		rep(_,0,n){
			ns[0].first += d.first;
			ns[0].second += d.second;
			rep(i,1,sz(ns)) {
				d2 = mp(ns[i-1].first - ns[i].first, ns[i-1].second - ns[i].second);
				if(max(abs(d2.first),abs(d2.second)) > 1) {
					if(abs(d2.first) > 0) {
						ns[i].first += d2.first > 0 ? 1 : -1;
					}
					if(abs(d2.second) > 0) {
						ns[i].second += d2.second > 0 ? 1 : -1;
					}
					if(i == 1) v1.insert(ns[i]);
					else if(i == 9) v9.insert(ns[i]);
				}
			}
		}
	}	
	cout << sz(v1) << "\n" << sz(v9);
}
