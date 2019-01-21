/*
 *  for this problem we'll maintain a mask that represents which side has at least 1 cheerleader in it
 *  simulate the process with transitions either pick or leave, turn on the mask based on the row/col positions
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) (((n%m) + m)%m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

const int mod = 1000007;

int memo[25][25][16][501];
int n, m, nn, mm, k;

int get(int r, int c)
{
	int ret = 0;
	if (r == 1)
		ret |= (1 << 0);
	if (r == n)
		ret |= (1 << 1);
	if (c == 1)
		ret |= (1 << 2);
	if (c == m)
		ret |= (1 << 3);
	return ret;
}

int solve(int r, int c, int mask, int rem)
{
	if (rem < 0)
		return 0;
	if (r == n && c == m + 1)
		return (mask == 15) && !rem;

	int &ret = memo[r][c][mask][rem];
	if (~ret)
		return ret;

	ret = 0;
	if (c == m + 1)
		return ret = solve(r + 1, 1, mask, rem);

	int a = get(r, c);

	ret = (ret + solve(r, c + 1, mask, rem)) % mod;
	ret = (ret + solve(r, c + 1, mask | a, rem - 1)) % mod;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	erep(t, 1, tc)
	{
		cin >> n >> m >> k;

		reset(memo, -1);
		cout << "Case " << t << ": ";
		cout << solve(1, 1, 0, k) << endl;
	}

	return 0;
}
