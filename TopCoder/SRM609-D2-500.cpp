#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<double>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define mapii map<int, int>
#define mapsi map<string, int>
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class PackingBallsDiv2 {
public:
	int minPacks(int R, int G, int B) {
		int ret = 0;
		ret += R/3;
		ret += G/3;
		ret += B/3;
		int rem = 0, rem2 = 0;
		rem = R%3, rem2 += (R%3 != 0);
		rem = max(rem, G%3), rem2 += (G%3 != 0);
		rem = max(rem, B%3), rem2 += (B%3 != 0);
		ret += min(rem, rem2);
		return ret;
	}
};
