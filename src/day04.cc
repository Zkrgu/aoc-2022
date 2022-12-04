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
	
	int a,b,c,d;
	char _;
	ll p1 = 0, p2 = 0;
	while(cin >> a >> _ >> b >> _ >> c >> _ >> d) {
		if(a >= c && b <= d || c >= a && d <= b) ++p1;
		if(a <= d && b >= c) ++p2;
	}
	cout << p1 << "\n" << p2;
}
