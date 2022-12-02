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
	int i = 0, n = 0;
	vi elves = {};
	while(getline(cin, s)) {
		if(s.empty()){
			++i;
		}else {
			n = stoi(s);
			if(elves.size() > i) {
				elves[i] += n;
			}else {
				elves.pb(n);
			}
		}
	}
	sort(all(elves), greater<int>());

	cout << elves[0] << "\n" << elves[0] + elves[1] + elves[2];
}
