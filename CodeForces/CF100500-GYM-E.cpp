/*
 *  since splitting the piles would lead into two independent games
 *  we should xor the grundy numbers of those games then generate our grundy number
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

int a, b, memo[55];

int grundy(int x)
{
	if (memo[x] != -1) return memo[x];

	if (x <= 0)
	{
		return 0;
	}

	int ret = 0;

	vb visited(55);

	erep(i, 0, (x-b)/2)
		visited[grundy(i) ^ grundy(x-i-b)] = true;

	while(visited[ret]) ret++;

	return memo[x] = ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	erep(t, 1, tc)
	{
		reset(memo, -1);
		cin >> a >> b;
		rep(i, 0, b) memo[i] = 0;

		cout << "Case " << t << ": ";
		if (grundy(a)) cout << "Winning\n";
		else cout << "Losing\n";
	}

	return 0;
}
