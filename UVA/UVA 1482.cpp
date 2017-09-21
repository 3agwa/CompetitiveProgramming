/*
 *  generate the grundy numbers a given number of stones in a pile
 *  observe the sequence, you can notice that 
 *  if N is even --> g(i) = i/2
 *  if N is odd then g(i) = g(i/2)
 *  now just xor the input values based on their grundy numbers and output the solution
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

	int ret = 0;
	vb visited(55);

	erep(i, 1, x/2)
		visited[grundy(x - i)] = true;

	while(visited[ret]) ret++;

	return memo[x] = ret;
}

ll get(ll x)
{
	while(x & 1) x/=2;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/*reset(memo, -1);

	memo[0] = memo[1] = 0;

	erep(i, 0, 50) grundy(i);

	erep(i, 0, 20) cerr << i << " " << memo[i] << endl;*/

	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		ll xorr = 0;
		rep(i, 0, n)
		{
			ll x;
			cin >> x;

			if (x%2 == 0) xorr ^= (x/2);
			else xorr ^= (get(x) / 2);
		}

		if (xorr) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
