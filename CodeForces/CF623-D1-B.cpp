/*
 *  since we can't remove all the array, we notice that either a[0] or a[n-1] will stay the same
 *  that being said, the changes that could happen to those is either stay the same, +1 or -1
 *  hence our solution is based on the prime factors of a[0], a[n-1] and their variations (+1, -1)
 *  we get the prime factors for these 6 numbers and dp on each one with state[idx][not opened/opened/closed]
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

const int N = 1e6 + 5;
int n, a, b;
int arr[N];
vi factors;

void factorize(int n)
{
	for (ll i = 2; i * i <= n; i++)
		while (n % i == 0)
			n /= i, factors.push_back(i);
	if (n != 1)
		factors.push_back(n);
}

ll memo[N][3];
int visited[N][3], id = 1, pr;

ll solve(int idx, int state)
{
	if (idx == n)
		return 0;
	ll &ret = memo[idx][state];
	if (visited[idx][state] == id)
		return ret;
	ret = 1e16;
	visited[idx][state] = id;

	if (!state)
	{
		if (arr[idx] % pr == 0)
			ret = min(ret, solve(idx + 1, state));
		if ((arr[idx] - 1) % pr == 0 || (arr[idx] + 1) % pr == 0)
			ret = min(ret, b + solve(idx + 1, state));
		ret = min(ret, a + solve(idx + 1, 1));
	}
	else if (state == 1)
	{
		if (arr[idx] % pr == 0)
			ret = min(ret, solve(idx + 1, 2));
		if ((arr[idx] - 1) % pr == 0 || (arr[idx] + 1) % pr == 0)
			ret = min(ret, b + solve(idx + 1, 2));
		ret = min(ret, a + solve(idx + 1, state));
	}
	else
	{
		if (arr[idx] % pr == 0)
			ret = min(ret, solve(idx + 1, state));
		if ((arr[idx] - 1) % pr == 0 || (arr[idx] + 1) % pr == 0)
			ret = min(ret, b + solve(idx + 1, state));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;
	rep(i, 0, n)
		cin >> arr[i];

	factorize(arr[0]);
	factorize(arr[0] - 1);
	factorize(arr[0] + 1);
	factorize(arr[n - 1]);
	factorize(arr[n - 1] - 1);
	factorize(arr[n - 1] + 1);

	sort(all(factors));
	factors.erase(unique(all(factors)), factors.end());

	ll res = 1e18;
	for (auto i : factors)
	{
		id++;
		pr = i;
		res = min(res, solve(0, 0));
	}
	cout << res << endl;
	return 0;
}
