#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;
typedef vector<vector<pii> > vvii;
typedef long double ld;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int accum[45][45], memo[45][45][45][45];
char arr[45][45];
int n, m, q;

int get(int a, int b, int c, int d)
{
	int ret = accum[c][d] - accum[a - 1][d] - accum[c][b - 1]
			+ accum[a - 1][b - 1];

	return !ret;
}

int solve(int a, int b, int c, int d)
{
	if (memo[a][b][c][d] != -1)
		return memo[a][b][c][d];

	int ret = get(a, b, c, d);

	if (c > a)
		ret += solve(a, b, c - 1, d);
	if (d > b)
		ret += solve(a, b, c, d - 1);
	if (c > a && d > b)
		ret -= solve(a, b, c - 1, d - 1);

	return memo[a][b][c][d] = ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	reset(memo, -1);

	erep(i, 1, n)
	{
		erep(j, 1, m)
		{
			cin >> arr[i][j];
			accum[i][j] = arr[i][j] - '0';
		}
	}

	erep(i, 1, n)
		erep(j, 1, m)
			accum[i][j] += (accum[i][j - 1] + accum[i - 1][j]
					- accum[i - 1][j - 1]);

	while (q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ret = 0;
		erep(i, a, c)
			erep(j, b, d)
				ret += solve(i, j, c, d);
		cout << ret << endl;
	}

	return 0;
}
