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

const int N = 5000 + 5;
int n, arr[N], xorr[N][N], memo[N], last[N], first[N];
bool valid[N][N], mp[N][N];

int mn[N][15], mx[N][15], lg[N];

void build()
{
	erep(j, 1, 14)
		for (int i = 1; i <= n - (1 << j) + 1; i++) // law 0 based hateb2a n - (1<<j), law 1 based hazawed + 1
		{
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
}

int qmin(int l, int r)
{
	if (l > r)
		swap(l, r);
	int j = lg[r - l + 1];

	if (mn[l][j] <= mn[r - (1 << j) + 1][j])
		return mn[l][j];
	return mn[r - (1 << j) + 1][j];
}

int qmax(int l, int r)
{
	if (l > r)
		swap(l, r);
	int j = lg[r - l + 1];

	if (mx[l][j] >= mx[r - (1 << j) + 1][j])
		return mx[l][j];
	return mx[r - (1 << j) + 1][j];
}

int solve(int idx)
{
	if (idx > n)
		return 0;

	int &ret = memo[idx];
	if (~ret)
		return ret;
	ret = solve(idx + 1);

	erep(i, idx, n)
		if (valid[idx][i])
			ret = max(ret, xorr[idx][i] + solve(i + 1));

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	lg[0] = -1;
	rep(i, 1, N)
		lg[i] = lg[i - 1] + !(i & (i - 1));

	cin >> n;
	erep(i, 1, n)
		cin >> arr[i], last[arr[i]] = i, first[arr[i]] = (
				!first[arr[i]] ? i : first[arr[i]]);
	erep(i, 1, n)
		mn[i][0] = first[arr[i]], mx[i][0] = last[arr[i]];

	build();
	reset(memo, -1);

	erep(i, 1, n)
	{
		erep(j, i, n)
		{
			xorr[i][j] ^= xorr[i][j - 1];
			if (!mp[i][arr[j]])
				mp[i][arr[j]] = true, xorr[i][j] ^= arr[j];
			if (qmin(i, j) >= i && qmax(i, j) <= j)
				valid[i][j] = true;
		}
	}

	cout << solve(1) << endl;

	return 0;
}
