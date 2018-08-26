#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(int i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) ((n%m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

int memo[5005][5005][2], n, a, b, k;

const int mod = 1e9 + 7;

int solve(int idx, int rem, bool range)
{
	if (idx == b)
		return 0;
	if (rem == 0)
		return 1;

	int &ret = memo[idx][rem][range];

	if (~ret)
		return ret;
	ret = 0;

	if (range)
	{
		if (idx > b)
			ret = solve(idx - 1, rem, 1);
		else
			ret = solve(idx + 1, rem, 1);
		ret += solve(idx, rem - 1, 0);

		if (ret >= mod)
			ret -= mod;
		return ret;
	}

	if (idx > b)
		ret = solve(min(2 * idx - b - 1, n), rem, 1);
	else
		ret = solve(max(2 * idx - b + 1, 1), rem, 1);

	ret -= solve(idx, rem - 1, 0); // included foo2
	if (ret < 0)
		ret += mod;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> k;

	reset(memo, -1);

	cout << solve(a, k, 0) << endl;

	return 0;
}
