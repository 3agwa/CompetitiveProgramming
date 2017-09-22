/*
 *  generate the grundy numbers for each pile then spot the sequence
 *  xor the grundy number of each pile size and output the solution accordingly
 */
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
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int a, b;

map< set<int>, int > memo[61];

int grundy(int x, set<int> st)
{
	if (!x) return 0;

	if (memo[x].find(st) != memo[x].end()) return memo[x][st];

	int ret = 0;

	set<int> hoba;

	erep(i, 1, x)
	{
		if (st.find(i) == st.end())
		{
			set<int> nxt = st;

			nxt.insert(i);

			hoba.insert(grundy(x-i, nxt));
		}
	}

	while(hoba.find(ret) != hoba.end()) ret++;
	return memo[x][st] = ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//set<int> st;
	//erep(i, 0, 20) cerr << i << " " << grundy(i, st) << endl;

	vi vec;
	vec.push_back(0);

	erep(i, 1, 15)
	{
		rep(j, 0, i+1) vec.push_back(i);
	}

	int xorr = 0;

	int n;
	cin >> n;

	rep(i, 0, n)
	{
		int x;
		cin >> x;
		xorr ^= vec[x];
	}

	if (!xorr) cout << "YES";
	else cout << "NO";

	return 0;
}
