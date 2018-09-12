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
#define mod(n, m) ((n%m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

string s, t;
vi fail;
vvi memo;
const int N = 1e5 + 5;
int nxt[N][26];

vector<int> computePrefix(string pat)
{
	int m = pat.size();
	vector<int> lp(m);
	for (int i = 1, k = 0; i < m; i++)
	{
		while (k > 0 && pat[k] != pat[i])
			k = lp[k - 1];
		if (pat[k] == pat[i])
			lp[i] = ++k;
		else
			lp[i] = k;
	}
	return lp;
}

int get_nxt(int i, int j)
{
	int &ret = nxt[i][j];
	if (~ret)
		return ret;

	int k = i;

	while (k > 0 && t[k] - 'a' != j)
		k = fail[k - 1];

	if (t[k] - 'a' == j)
		k++;

	return ret = k;
}

int solve(int idx, int last)
{
	if (idx == sz(s))
		return 0;

	int &ret = memo[idx][last];
	if (~ret)
		return ret;
	ret = 0;

	if (s[idx] == '?') // ha3raf a7ot aii 7aga
	{
		rep(i, 0, 26)
		{
			int n = get_nxt(last, i); // a5er character hayroo7 le meen

			ret = max(ret, (n == sz(t)) + solve(idx + 1, n));
		}
	}
	else
	{
		int n = get_nxt(last, s[idx] - 'a');
		ret = max(ret, (n == sz(t)) + solve(idx + 1, n));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	fail = computePrefix(t);
	reset(nxt, -1);
	memo = vvi(sz(s) + 1, vi(sz(t) + 1, -1));

	cout << solve(0, 0) << endl;
	return 0;
}
